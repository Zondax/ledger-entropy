# Ledger Entropy App

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![GithubActions](https://github.com/zondax/ledger-entropy/actions/workflows/main.yml/badge.svg)](https://github.com/Zondax/ledger-entropy/blob/main/.github/workflows/main.yaml)

---

![zondax_light](docs/zondax_light.png#gh-light-mode-only)
![zondax_dark](docs/zondax_dark.png#gh-dark-mode-only)

_Please visit our website at [zondax.ch](https://www.zondax.ch)_

---

This project contains the Entropy app (https://entropy.xyz/) for Ledger Nano S, S+, X and Stax.

- Ledger BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information: [How to build](docs/build.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**
# Entropy 7.200.x

## System

| Name                             | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                         |
| -------------------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------- |
| Remark                           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |
| Set heap pages                   |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`pages<br/>                   |
| Set code                         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`code<br/>                  |
| Set code without checks          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`code<br/>                  |
| Set storage                      |        |                    |                    |                    | `VecKeyValue`items<br/>           |
| Kill storage                     |        |                    |                    |                    | `VecKey`keys<br/>                 |
| Kill prefix                      |        |                    |                    |                    | `Key`prefix<br/>`u32`subkeys<br/> |
| Remark with event                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |
| Authorize upgrade                |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Hash`code_hash<br/>              |
| Authorize upgrade without checks |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Hash`code_hash<br/>              |
| Apply authorized upgrade         |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Vecu8`code<br/>                  |

## Utility

| Name          | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                       |
| ------------- | ------------------ | ------------------ | ------------------ | ------- | ----------------------------------------------- |
| Batch         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| As derivative |                    |                    |                    |         | `u16`index<br/>`Call`call<br/>                  |
| Batch all     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| Dispatch as   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `BoxPalletsOrigin`as_origin<br/>`Call`call<br/> |
| Force batch   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| With weight   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `Call`call<br/>`Weight`weight<br/>              |

## Babe

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                              |
| ---------------------------- | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------------------------------- |
| Report equivocation          |        |           |                  |         | `BoxEquivocationProofHeader`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Report equivocation unsigned |        |           |                  |         | `BoxEquivocationProofHeader`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Plan config change           |        |           |                  |         | `NextConfigDescriptor`config<br/>                                                      |

## Timestamp

| Name | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments            |
| ---- | ------ | --------- | ---------------- | ------- | -------------------- |
| Set  |        |           |                  |         | `Compactu64`now<br/> |

## Indices

| Name           | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                               |
| -------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------- |
| Claim          |        |           |                  |         | `AccountIndex`index<br/>                                                |
| Transfer       |        |           |                  |         | `AccountIdLookupOfT`new\_<br/>`AccountIndex`index<br/>                  |
| Free           |        |           |                  |         | `AccountIndex`index<br/>                                                |
| Force transfer |        |           |                  |         | `AccountIdLookupOfT`new\_<br/>`AccountIndex`index<br/>`bool`freeze<br/> |
| Freeze         |        |           |                  |         | `AccountIndex`index<br/>                                                |

## Balances

| Name                        | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                               |
| --------------------------- | ------------------ | ------------------ | ------------------ | ------------------ | --------------------------------------------------------------------------------------- |
| Transfer allow death        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                |
| Force transfer              | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/> |
| Transfer keep alive         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                |
| Transfer all                | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                      |
| Force unreserve             |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`Balance`amount<br/>                                        |
| Upgrade accounts            |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecAccountId`who<br/>                                                                  |
| Force set balance           |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>                               |
| Force adjust total issuance |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AdjustmentDirection`direction<br/>`CompactBalance`delta<br/>                           |

## ElectionProviderMultiPhase

| Name                          | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                  |
| ----------------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------ |
| Submit unsigned               |        |           |                  |         | `BoxRawSolutionSolutionOfMinerConfig`raw_solution<br/>`SolutionOrSnapshotSize`witness<br/> |
| Set minimum untrusted score   |        |           |                  |         | `OptionElectionScore`maybe_next_score<br/>                                                 |
| Set emergency election result |        |           |                  |         | `SupportsAccountId`supports<br/>                                                           |
| Submit                        |        |           |                  |         | `BoxRawSolutionSolutionOfMinerConfig`raw_solution<br/>                                     |
| Governance fallback           |        |           |                  |         | `Optionu32`maybe_max_voters<br/>`Optionu32`maybe_max_targets<br/>                          |

## Staking

| Name                       | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                                                                                                                                 |
| -------------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Bond                       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>`RewardDestination`payee<br/>                                                                                                                                                                                  |
| Bond extra                 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Unbond                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Withdraw Unbonded          | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u32`num_slashing_spans<br/>                                                                                                                                                                                                              |
| Validate                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ValidatorPrefs`prefs<br/>                                                                                                                                                                                                                |
| Nominate                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountIdLookupOfT`targets<br/>                                                                                                                                                                                                       |
| Chill                      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                                                                                                                           |
| Set payee                  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `RewardDestination`payee<br/>                                                                                                                                                                                                             |
| Set controller             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                                                                                                                           |
| Set validator count        |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`new\_<br/>                                                                                                                                                                                                                    |
| Increase validator count   |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`additional<br/>                                                                                                                                                                                                               |
| Scale validator count      |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Percent`factor<br/>                                                                                                                                                                                                                      |
| Force no eras              |                    | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                                                                                                                                           |
| Force new era              |                    | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                                                                                                                                           |
| Set invulnerables          |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecAccountId`invulnerables<br/>                                                                                                                                                                                                          |
| Force unstake              |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`stash<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                                         |
| Force new era always       |                    | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                                                                                                                                           |
| Cancel deferred slash      |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `EraIndex`era<br/>`Vecu32`slash_indices<br/>                                                                                                                                                                                              |
| Payout stakers             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`validator_stash<br/>`EraIndex`era<br/>                                                                                                                                                                                         |
| Rebond                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Reap stash                 |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`stash<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                                         |
| Kick                       |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecAccountIdLookupOfT`who<br/>                                                                                                                                                                                                           |
| Set staking configs        |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `ConfigOpBalanceOfT`min_nominator_bond<br/>`ConfigOpBalanceOfT`min_validator_bond<br/>`ConfigOpu32`max_nominator_count<br/>`ConfigOpu32`max_validator_count<br/>`ConfigOpPercent`chill_threshold<br/>`ConfigOpPerbill`min_commission<br/> |
| Chill other                |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`stash<br/>                                                                                                                                                                                                                     |
| Force apply min commission |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`validator_stash<br/>                                                                                                                                                                                                           |
| Set min commission         |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Perbill`new\_<br/>                                                                                                                                                                                                                       |
| Payout stakers by page     |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`validator_stash<br/>`EraIndex`era<br/>`Page`page<br/>                                                                                                                                                                          |
| Update payee               |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`controller<br/>                                                                                                                                                                                                                |
| Deprecate controller batch |                    |                    |                    |                    | `BoundedVecAccountIdMaxControllersInDeprecationBatch`controllers<br/>                                                                                                                                                                     |
| Restore ledger             |                    |                    |                    |                    | `AccountId`stash<br/>`OptionAccountId`maybe_controller<br/>`OptionBalance`maybe_total<br/>`OptionBoundedVecUnlockChunkBalanceOfTMaxUnlockingChunks`maybe_unlocking<br/>                                                                   |

## StakingExtension

| Name                      | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                          |
| ------------------------- | ------ | ------------------ | ------------------ | ------- | ------------------------------------------------------------------ |
| Change endpoint           |        | :heavy_check_mark: | :heavy_check_mark: |         | `Vecu8`endpoint<br/>                                               |
| Change threshold accounts |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`tss_account<br/>`X25519PublicKey`x25519_public_key<br/> |
| Withdraw Unbonded         |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`num_slashing_spans<br/>                                       |
| Validate                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `ValidatorPrefs`prefs<br/>`ServerInfoAccountId`server_info<br/>    |
| Declare synced            |        | :heavy_check_mark: | :heavy_check_mark: |         | `bool`synced<br/>                                                  |

## Session

| Name       | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                        |
| ---------- | ------------------ | ------------------ | ------------------ | ------------------ | -------------------------------- |
| Set keys   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Keys`keys<br/>`Bytes`proof<br/> |
| Purge keys | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                  |

## Democracy

| Name                      | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                      |
| ------------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------ |
| Propose                   |        |           |                  |         | `BoundedCallOfT`proposal<br/>`CompactBalance`amount<br/>                       |
| Second                    |        |           |                  |         | `Compactu32`proposal<br/>                                                      |
| Vote                      |        |           |                  |         | `Compactu32`ref_index<br/>`AccountVote`vote<br/>                               |
| Emergency cancel          |        |           |                  |         | `ReferendumIndex`ref_index<br/>                                                |
| External propose          |        |           |                  |         | `BoundedCallOfT`proposal<br/>                                                  |
| External propose majority |        |           |                  |         | `BoundedCallOfT`proposal<br/>                                                  |
| External propose default  |        |           |                  |         | `BoundedCallOfT`proposal<br/>                                                  |
| Fast track                |        |           |                  |         | `Hash`proposal_hash<br/>`BlockNumber`voting_period<br/>`BlockNumber`delay<br/> |
| Veto external             |        |           |                  |         | `Hash`proposal_hash<br/>                                                       |
| Cancel referendum         |        |           |                  |         | `Compactu32`ref_index<br/>                                                     |
| Delegate                  |        |           |                  |         | `AccountIdLookupOfT`to<br/>`Conviction`conviction<br/>`Balance`balance<br/>    |
| Undelegate                |        |           |                  |         |                                                                                |
| Clear public proposals    |        |           |                  |         |                                                                                |
| Unlock                    |        |           |                  |         | `AccountIdLookupOfT`target<br/>                                                |
| Remove vote               |        |           |                  |         | `ReferendumIndex`index<br/>                                                    |
| Remove other vote         |        |           |                  |         | `AccountIdLookupOfT`target<br/>`ReferendumIndex`index<br/>                     |
| Blacklist                 |        |           |                  |         | `Hash`proposal_hash<br/>`OptionReferendumIndex`maybe_ref_index<br/>            |
| Cancel proposal           |        |           |                  |         | `Compactu32`prop_index<br/>                                                    |
| Set metadata              |        |           |                  |         | `MetadataOwner`owner<br/>`OptionHash`maybe_hash<br/>                           |

## Council

| Name                | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                     |
| ------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------- |
| Set members         |        |           |                  |         | `VecAccountId`new_members<br/>`OptionAccountId`prime<br/>`MemberCount`old_count<br/>                          |
| Execute             |        |           |                  |         | `Proposal`proposal<br/>`Compactu32`length_bound<br/>                                                          |
| Propose             |        |           |                  |         | `Compactu32`threshold<br/>`Proposal`proposal<br/>`Compactu32`length_bound<br/>                                |
| Vote                |        |           |                  |         | `Hash`proposal<br/>`Compactu32`index<br/>`bool`approve<br/>                                                   |
| Disapprove proposal |        |           |                  |         | `Hash`proposal_hash<br/>                                                                                      |
| Close               |        |           |                  |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Weight`proposal_weight_bound<br/>`Compactu32`length_bound<br/> |

## TechnicalCommittee

| Name                | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                     |
| ------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------- |
| Set members         |        |           |                  |         | `VecAccountId`new_members<br/>`OptionAccountId`prime<br/>`MemberCount`old_count<br/>                          |
| Execute             |        |           |                  |         | `Proposal`proposal<br/>`Compactu32`length_bound<br/>                                                          |
| Propose             |        |           |                  |         | `Compactu32`threshold<br/>`Proposal`proposal<br/>`Compactu32`length_bound<br/>                                |
| Vote                |        |           |                  |         | `Hash`proposal<br/>`Compactu32`index<br/>`bool`approve<br/>                                                   |
| Disapprove proposal |        |           |                  |         | `Hash`proposal_hash<br/>                                                                                      |
| Close               |        |           |                  |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Weight`proposal_weight_bound<br/>`Compactu32`length_bound<br/> |

## Elections

| Name                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                  |
| -------------------- | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------------------- |
| Vote                 |        |           |                  |         | `VecAccountId`votes<br/>`Compactu128`amount<br/>                           |
| Remove voter         |        |           |                  |         |                                                                            |
| Submit candidacy     |        |           |                  |         | `Compactu32`candidate_count<br/>                                           |
| Renounce candidacy   |        |           |                  |         | `Renouncing`renouncing<br/>                                                |
| Remove member        |        |           |                  |         | `AccountIdLookupOfT`who<br/>`bool`slash_bond<br/>`bool`rerun_election<br/> |
| Clean defunct voters |        |           |                  |         | `u32`num_voters<br/>`u32`num_defunct<br/>                                  |

## TechnicalMembership

| Name          | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                   |
| ------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------- |
| Add member    |        |           |                  |         | `AccountIdLookupOfT`who<br/>                                |
| Remove member |        |           |                  |         | `AccountIdLookupOfT`who<br/>                                |
| Swap member   |        |           |                  |         | `AccountIdLookupOfT`remove<br/>`AccountIdLookupOfT`add<br/> |
| Reset members |        |           |                  |         | `VecAccountId`members<br/>                                  |
| Change key    |        |           |                  |         | `AccountIdLookupOfT`new\_<br/>                              |
| Set prime     |        |           |                  |         | `AccountIdLookupOfT`who<br/>                                |
| Clear prime   |        |           |                  |         |                                                             |

## Grandpa

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                       |
| ---------------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------- |
| Report equivocation          |        |           |                  |         | `BoxEquivocationProofHashBlockNumber`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Report equivocation unsigned |        |           |                  |         | `BoxEquivocationProofHashBlockNumber`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Note stalled                 |        |           |                  |         | `BlockNumber`delay<br/>`BlockNumber`best_finalized_block_number<br/>                            |

## Treasury

| Name             | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                          |
| ---------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------------------------------------------------------------------------- |
| Propose spend    |        |           |                  |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/>                                                                    |
| Reject proposal  |        |           |                  |         | `Compactu32`proposal_id<br/>                                                                                                       |
| Approve proposal |        |           |                  |         | `Compactu32`proposal_id<br/>                                                                                                       |
| Spend local      |        |           |                  |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/>                                                                    |
| Remove approval  |        |           |                  |         | `Compactu32`proposal_id<br/>                                                                                                       |
| Spend            |        |           |                  |         | `BoxAssetKind`asset_kind<br/>`CompactBalance`amount<br/>`BoxBeneficiaryLookupOf`beneficiary<br/>`OptionBlockNumber`valid_from<br/> |
| Payout           |        |           |                  |         | `SpendIndex`index<br/>                                                                                                             |
| Check status     |        |           |                  |         | `SpendIndex`index<br/>                                                                                                             |
| Void spend       |        |           |                  |         | `SpendIndex`index<br/>                                                                                                             |

## Sudo

| Name                  | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                   |
| --------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------- |
| Sudo                  |        |           |                  |         | `Call`call<br/>                             |
| Sudo unchecked weight |        |           |                  |         | `Call`call<br/>`Weight`weight<br/>          |
| Set key               |        |           |                  |         | `AccountIdLookupOfT`new\_<br/>              |
| Sudo as               |        |           |                  |         | `AccountIdLookupOfT`who<br/>`Call`call<br/> |
| Remove key            |        |           |                  |         |                                             |

## ImOnline

| Name      | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                  |
| --------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------ |
| Heartbeat |        |           |                  |         | `HeartbeatBlockNumber`heartbeat<br/>`AuthorityIdasRuntimeAppPublicSignature`signature<br/> |

## Identity

| Name                      | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                       |
| ------------------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------------------------------------------------------- |
| Add registrar             |        |           |                  |         | `AccountIdLookupOfT`account<br/>                                                                                |
| Set identity              |        |           |                  |         | `IdentityInfo`info<br/>                                                                                         |
| Set subs                  |        |           |                  |         | `VecTupleAccountIdData`subs<br/>                                                                                |
| Clear identity            |        |           |                  |         |                                                                                                                 |
| Request judgement         |        |           |                  |         | `Compactu32`reg_index<br/>`Compactu128`max_fee<br/>                                                             |
| Cancel request            |        |           |                  |         | `RegistrarIndex`reg_index<br/>                                                                                  |
| Set fee                   |        |           |                  |         | `Compactu32`index<br/>`Compactu128`fee<br/>                                                                     |
| Set account id            |        |           |                  |         | `Compactu32`index<br/>`AccountIdLookupOfT`new\_<br/>                                                            |
| Set fields                |        |           |                  |         | `Compactu32`index<br/>`IdentityInformationasIdentityInformationProviderFieldsIdentifier`fields<br/>             |
| Provide judgement         |        |           |                  |         | `Compactu32`reg_index<br/>`AccountIdLookupOfT`target<br/>`JudgementBalanceOfT`judgement<br/>`Hash`identity<br/> |
| Kill identity             |        |           |                  |         | `AccountIdLookupOfT`target<br/>                                                                                 |
| Add sub                   |        |           |                  |         | `AccountIdLookupOfT`sub<br/>`Data`data<br/>                                                                     |
| Rename sub                |        |           |                  |         | `AccountIdLookupOfT`sub<br/>`Data`data<br/>                                                                     |
| Remove sub                |        |           |                  |         | `AccountIdLookupOfT`sub<br/>                                                                                    |
| Quit sub                  |        |           |                  |         |                                                                                                                 |
| Add username authority    |        |           |                  |         | `AccountIdLookupOfT`authority<br/>`Vecu8`suffix<br/>`u32`allocation<br/>                                        |
| Remove username authority |        |           |                  |         | `AccountIdLookupOfT`authority<br/>                                                                              |
| Set username for          |        |           |                  |         | `AccountIdLookupOfT`who<br/>`Vecu8`username<br/>`OptionOffchainSignature`signature<br/>                         |
| Accept username           |        |           |                  |         | `UsernameT`username<br/>                                                                                        |
| Remove expired approval   |        |           |                  |         | `UsernameT`username<br/>                                                                                        |
| Set primary username      |        |           |                  |         | `UsernameT`username<br/>                                                                                        |
| Remove dangling username  |        |           |                  |         | `UsernameT`username<br/>                                                                                        |

## Recovery

| Name              | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                   |
| ----------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------------------- |
| As recovered      |        |           |                  |         | `AccountIdLookupOfT`account<br/>`Call`call<br/>                             |
| Set recovered     |        |           |                  |         | `AccountIdLookupOfT`lost<br/>`AccountIdLookupOfT`rescuer<br/>               |
| Create recovery   |        |           |                  |         | `VecAccountId`friends<br/>`u16`threshold<br/>`BlockNumber`delay_period<br/> |
| Initiate recovery |        |           |                  |         | `AccountIdLookupOfT`account<br/>                                            |
| Vouch recovery    |        |           |                  |         | `AccountIdLookupOfT`lost<br/>`AccountIdLookupOfT`rescuer<br/>               |
| Claim recovery    |        |           |                  |         | `AccountIdLookupOfT`account<br/>                                            |
| Close recovery    |        |           |                  |         | `AccountIdLookupOfT`rescuer<br/>                                            |
| Remove recovery   |        |           |                  |         |                                                                             |
| Cancel recovered  |        |           |                  |         | `AccountIdLookupOfT`account<br/>                                            |

## Vesting

| Name                          | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                |
| ----------------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------------------------------- |
| Vest                          |        |           |                  |         |                                                                                          |
| Vest other                    |        |           |                  |         | `AccountIdLookupOfT`target<br/>                                                          |
| Vested transfer               |        |           |                  |         | `AccountIdLookupOfT`target<br/>`VestingInfo`schedule<br/>                                |
| Force vested transfer         |        |           |                  |         | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`target<br/>`VestingInfo`schedule<br/> |
| Merge schedules               |        |           |                  |         | `u32`schedule1_index<br/>`u32`schedule2_index<br/>                                       |
| Force remove vesting schedule |        |           |                  |         | `LookupasStaticLookupSource`target<br/>`u32`schedule_index<br/>                          |

## Scheduler

| Name                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                  |
| -------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
| Schedule             |        |           |                  |         | `BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>                   |
| Cancel               |        |           |                  |         | `BlockNumber`when<br/>`u32`index<br/>                                                                                                      |
| Schedule named       |        |           |                  |         | `TaskName`id<br/>`BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>  |
| Cancel named         |        |           |                  |         | `TaskName`id<br/>                                                                                                                          |
| Schedule after       |        |           |                  |         | `BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>                  |
| Schedule named after |        |           |                  |         | `TaskName`id<br/>`BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/> |

## Preimage

| Name               | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments            |
| ------------------ | ------ | --------- | ---------------- | ------- | -------------------- |
| Note preimage      |        |           |                  |         | `Vecu8`bytes<br/>    |
| Unnote preimage    |        |           |                  |         | `Hash`hash<br/>      |
| Request preimage   |        |           |                  |         | `Hash`hash<br/>      |
| Unrequest preimage |        |           |                  |         | `Hash`hash<br/>      |
| Ensure updated     |        |           |                  |         | `VecHash`hashes<br/> |

## Proxy

| Name                | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                  |
| ------------------- | ------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------------------------------------------------------------------- |
| Proxy               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`real<br/>`OptionProxyType`force_proxy_type<br/>`Call`call<br/>                                         |
| Add proxy           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`delegate<br/>`ProxyType`proxy_type<br/>`BlockNumber`delay<br/>                                         |
| Remove proxy        |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`delegate<br/>`ProxyType`proxy_type<br/>`BlockNumber`delay<br/>                                         |
| Remove proxies      |        | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                            |
| Create pure         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ProxyType`proxy_type<br/>`BlockNumber`delay<br/>`u16`index<br/>                                                           |
| Kill pure           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`spawner<br/>`ProxyType`proxy_type<br/>`u16`index<br/>`Compactu32`height<br/>`Compactu32`ext_index<br/> |
| Announce            |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`real<br/>`CallHashOf`call_hash<br/>                                                                    |
| Remove announcement |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`real<br/>`CallHashOf`call_hash<br/>                                                                    |
| Reject announcement |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`delegate<br/>`CallHashOf`call_hash<br/>                                                                |
| Proxy announced     |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`delegate<br/>`AccountIdLookupOfT`real<br/>`OptionProxyType`force_proxy_type<br/>`Call`call<br/>        |

## Multisig

| Name                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                               |
| -------------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| As multi threshold 1 |        |           |                  |         | `VecAccountId`other_signatories<br/>`Call`call<br/>                                                                                     |
| As multi             |        |           |                  |         | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`Call`call<br/>`Weight`max_weight<br/>      |
| Approve as multi     |        |           |                  |         | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`H256`call_hash<br/>`Weight`max_weight<br/> |
| Cancel as multi      |        |           |                  |         | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`Timepoint`timepoint<br/>`H256`call_hash<br/>                                    |

## Bounties

| Name                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                          |
| -------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------------------------- |
| Propose bounty       |        |           |                  |         | `CompactBalance`amount<br/>`Bytes`description<br/>                                 |
| Approve bounty       |        |           |                  |         | `Compactu32`bounty_id<br/>                                                         |
| Propose curator      |        |           |                  |         | `Compactu32`bounty_id<br/>`AccountIdLookupOfT`curator<br/>`CompactBalance`fee<br/> |
| Unassign curator     |        |           |                  |         | `Compactu32`bounty_id<br/>                                                         |
| Accept curator       |        |           |                  |         | `Compactu32`bounty_id<br/>                                                         |
| Award bounty         |        |           |                  |         | `Compactu32`bounty_id<br/>`AccountIdLookupOfT`beneficiary<br/>                     |
| Claim bounty         |        |           |                  |         | `Compactu32`bounty_id<br/>                                                         |
| Close bounty         |        |           |                  |         | `Compactu32`bounty_id<br/>                                                         |
| Extend bounty expiry |        |           |                  |         | `Compactu32`bounty_id<br/>`Bytes`remark<br/>                                       |

## Tips

| Name           | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                 |
| -------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------- |
| Report awesome |        |           |                  |         | `Bytes`reason<br/>`AccountIdLookupOfT`who<br/>                            |
| Retract tip    |        |           |                  |         | `Hash`hash<br/>                                                           |
| Tip new        |        |           |                  |         | `Bytes`reason<br/>`AccountIdLookupOfT`who<br/>`Compactu128`tip_value<br/> |
| Tip            |        |           |                  |         | `Hash`hash<br/>`Compactu128`tip_value<br/>                                |
| Close tip      |        |           |                  |         | `Hash`hash<br/>                                                           |
| Slash tip      |        |           |                  |         | `Hash`hash<br/>                                                           |

## TransactionStorage

| Name        | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                              |
| ----------- | ------ | --------- | ---------------- | ------- | -------------------------------------- |
| Store       |        |           |                  |         | `Vecu8`data<br/>                       |
| Renew       |        |           |                  |         | `BlockNumber`block<br/>`u32`index<br/> |
| Check proof |        |           |                  |         | `TransactionStorageProof`proof<br/>    |

## BagsList

| Name                  | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                        |
| --------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------------------- |
| Rebag                 |        |           |                  |         | `AccountIdLookupOfT`dislocated<br/>                              |
| Put in front of       |        |           |                  |         | `AccountIdLookupOfT`lighter<br/>                                 |
| Put in front of other |        |           |                  |         | `AccountIdLookupOfT`heavier<br/>`AccountIdLookupOfT`lighter<br/> |

## NominationPools

| Name                            | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                                                                               |
| ------------------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Join                            |        |           |                  |         | `CompactBalance`amount<br/>`PoolId`pool_id<br/>                                                                                                                                                                         |
| Bond extra                      |        |           |                  |         | `BondExtraBalanceOfT`extra<br/>                                                                                                                                                                                         |
| Claim payout                    |        |           |                  |         |                                                                                                                                                                                                                         |
| Unbond                          |        |           |                  |         | `AccountIdLookupOfT`member_account<br/>`CompactBalance`unbonding_points<br/>                                                                                                                                            |
| Pool withdraw unbonded          |        |           |                  |         | `PoolId`pool_id<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                        |
| Withdraw Unbonded               |        |           |                  |         | `AccountIdLookupOfT`member_account<br/>`u32`num_slashing_spans<br/>                                                                                                                                                     |
| Create                          |        |           |                  |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`root<br/>`AccountIdLookupOfT`nominator<br/>`AccountIdLookupOfT`bouncer<br/>                                                                                              |
| Create with pool id             |        |           |                  |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`root<br/>`AccountIdLookupOfT`nominator<br/>`AccountIdLookupOfT`bouncer<br/>`PoolId`pool_id<br/>                                                                          |
| Nominate                        |        |           |                  |         | `PoolId`pool_id<br/>`VecAccountId`validators<br/>                                                                                                                                                                       |
| Set state                       |        |           |                  |         | `PoolId`pool_id<br/>`PoolState`state<br/>                                                                                                                                                                               |
| Set metadata                    |        |           |                  |         | `PoolId`pool_id<br/>`Vecu8`metadata<br/>                                                                                                                                                                                |
| Set configs                     |        |           |                  |         | `ConfigOpBalanceOfT`min_join_bond<br/>`ConfigOpBalanceOfT`min_create_bond<br/>`ConfigOpu32`max_pools<br/>`ConfigOpu32`max_members<br/>`ConfigOpu32`max_members_per_pool<br/>`ConfigOpPerbill`global_max_commission<br/> |
| Update roles                    |        |           |                  |         | `PoolId`pool_id<br/>`ConfigOpAccountId`new_root<br/>`ConfigOpAccountId`new_nominator<br/>`ConfigOpAccountId`new_bouncer<br/>                                                                                            |
| Chill                           |        |           |                  |         | `PoolId`pool_id<br/>                                                                                                                                                                                                    |
| Bond extra other                |        |           |                  |         | `AccountIdLookupOfT`member<br/>`BondExtraBalanceOfT`extra<br/>                                                                                                                                                          |
| Set claim permission            |        |           |                  |         | `ClaimPermission`permission<br/>                                                                                                                                                                                        |
| Claim payout other              |        |           |                  |         | `AccountId`other<br/>                                                                                                                                                                                                   |
| Set commission                  |        |           |                  |         | `PoolId`pool_id<br/>`OptionTuplePerbillAccountId`new_commission<br/>                                                                                                                                                    |
| Set commission max              |        |           |                  |         | `PoolId`pool_id<br/>`Perbill`max_commission<br/>                                                                                                                                                                        |
| Set commission change rate      |        |           |                  |         | `PoolId`pool_id<br/>`CommissionChangeRateBlockNumber`change_rate<br/>                                                                                                                                                   |
| Claim commission                |        |           |                  |         | `PoolId`pool_id<br/>                                                                                                                                                                                                    |
| Adjust pool deposit             |        |           |                  |         | `PoolId`pool_id<br/>                                                                                                                                                                                                    |
| Set commission claim permission |        |           |                  |         | `PoolId`pool_id<br/>`OptionCommissionClaimPermissionAccountId`permission<br/>                                                                                                                                           |

## Registry

| Name                                | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                    |
| ----------------------------------- | ------ | ------------------ | ------------------ | ------- | -------------------------------------------------------------------------------------------------------------------------------------------- |
| Register                            |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`program_modification_account<br/>`KeyVisibility`key_visibility<br/>`BoundedVecProgramInstanceTMaxProgramHashes`programs_data<br/> |
| Prune registration                  |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                                                                              |
| Change program instance             |        | :heavy_check_mark: | :heavy_check_mark: |         | `VerifyingKey`verifying_key<br/>`BoundedVecProgramInstanceTMaxProgramHashes`new_program_instance<br/>                                        |
| Change program modification account |        | :heavy_check_mark: | :heavy_check_mark: |         | `VerifyingKey`verifying_key<br/>`AccountId`new_program_mod_account<br/>                                                                      |
| Confirm register                    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`sig_req_account<br/>`u8`signing_subgroup<br/>`BoundedVecu8`verifying_key<br/>                                                     |

## Slashing

| Name | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments |
| ---- | ------ | --------- | ---------------- | ------- | --------- |

## Programs

| Name           | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                               |
| -------------- | ------ | ------------------ | ------------------ | ------- | ----------------------------------------------------------------------------------------------------------------------- |
| Set program    |        | :heavy_check_mark: | :heavy_check_mark: |         | `Vecu8`new_program<br/>`Vecu8`configuration_schema<br/>`Vecu8`auxiliary_data_schema<br/>`Vecu8`oracle_data_pointer<br/> |
| Remove program |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`program_hash<br/>                                                                                                 |

## TransactionPause

| Name                | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                        |
| ------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------ |
| Pause transaction   |        |           |                  |         | `Vecu8`pallet_name<br/>`Vecu8`function_name<br/> |
| Unpause transaction |        |           |                  |         | `Vecu8`pallet_name<br/>`Vecu8`function_name<br/> |

## Propagation

| Name | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments |
| ---- | ------ | --------- | ---------------- | ------- | --------- |

## Parameters

| Name                                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                               |
| ------------------------------------ | ------ | --------- | ---------------- | ------- | --------------------------------------- |
| Change request limit                 |        |           |                  |         | `u32`request_limit<br/>                 |
| Change max instructions per programs |        |           |                  |         | `u64`max_instructions_per_programs<br/> |
