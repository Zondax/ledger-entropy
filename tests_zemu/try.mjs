import TransportNodeHid from '@ledgerhq/hw-transport-node-hid'
import { newSubstrateApp } from '@zondax/ledger-substrate'
import ed25519 from 'ed25519-supercop'
import blakejs from 'blakejs';
const { blake2bFinal, blake2bInit, blake2bUpdate } = blakejs;

async function main() {
  const transport = await TransportNodeHid.default.open();

  const app = newSubstrateApp(transport, 'Entropy')

  const pathAccount = 0x80000000
  const pathChange = 0x80000000
  const pathIndex = 0x80000000

  const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  const pubKey = Buffer.from(responseAddr.pubKey, 'hex')
  console.log(responseAddr)

  let resp = await app.appInfo()
  console.log('App info', resp);

  resp = await app.getVersion()
  console.log('Version', resp);

  const txBalances =
     '070000313233343536373839303132333435363738393031323334353637383930313233158139ae28a3dfaac5fe1560a5e9e05cd5038d2433158139ae28a3dfaac5fe1560a5e9e05c64000000060000002ff566103dfac49018be96ef1adfac8dd1d6852ef65c984f0ee6d6a105d3aaef2ff566103dfac49018be96ef1adfac8dd1d6852ef65c984f0ee6d6a105d3aaef'

  const txBlob = Buffer.from(txBalances, 'hex')
  const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

  const signatureResponse = await signatureRequest
  console.log(signatureResponse)

  // Now verify the signature
  let prehash = txBlob
  if (txBlob.length > 256) {
    const context = blake2bInit(32)
    blake2bUpdate(context, txBlob)
    prehash = Buffer.from(blake2bFinal(context))
  }
  const valid = ed25519.verify(signatureResponse.signature.subarray(1), prehash, pubKey)
  if (valid) {
    console.log("Valid signature")
  } else {
    console.log("Invalid signature")
  }
}

; (async () => {
  await main()
})()