/*******************************************************************************
 *  (c) 2019 - 2024 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

// Common read functions

parser_error_t _readbool(parser_context_t *c, pd_bool_t *v);
parser_error_t _readu8(parser_context_t *c, pd_u8_t *v);
parser_error_t _readu16(parser_context_t *c, pd_u16_t *v);
parser_error_t _readu32(parser_context_t *c, pd_u32_t *v);
parser_error_t _readu64(parser_context_t *c, pd_u64_t *v);
parser_error_t _readBlockNumber(parser_context_t *c, pd_BlockNumber_t *v);
parser_error_t _readCompactu32(parser_context_t *c, pd_Compactu32_t *v);
parser_error_t _readCompactu64(parser_context_t *c, pd_Compactu64_t *v);
parser_error_t _readCallImpl(parser_context_t *c, pd_Call_t *v, pd_MethodNested_t *m);

parser_error_t _readProgramConfig(parser_context_t *c, pd_ProgramConfig_t *v);
parser_error_t _readProgramPointer(parser_context_t *c, pd_ProgramPointer_t *v);
parser_error_t _readAccountId(parser_context_t *c, pd_AccountId_t *v);
parser_error_t _readBytes(parser_context_t *c, pd_Bytes_t *v);
parser_error_t _readCompactAccountIndex(parser_context_t *c, pd_CompactAccountIndex_t *v);
parser_error_t _readMembers(parser_context_t *c, pd_Members_t *v);
parser_error_t _readProgramInstanceTMaxProgramHashes(parser_context_t *c, pd_ProgramInstanceTMaxProgramHashes_t *v);
parser_error_t _readAccountIdLookupOfT(parser_context_t *c, pd_AccountIdLookupOfT_t *v);
parser_error_t _readBalance(parser_context_t *c, pd_Balance_t *v);
parser_error_t _readCall(parser_context_t *c, pd_Call_t *v);
parser_error_t _readCompactPerBill(parser_context_t *c, pd_CompactPerBill_t *v);
parser_error_t _readCouncil(parser_context_t *c, pd_Council_t *v);
parser_error_t _readPerbill(parser_context_t *c, pd_Perbill_t *v);
parser_error_t _readPercent(parser_context_t *c, pd_Percent_t *v);
parser_error_t _readProxyType(parser_context_t *c, pd_ProxyType_t *v);
parser_error_t _readSystemOrigin(parser_context_t *c, pd_SystemOrigin_t *v);
parser_error_t _readTssServerURL(parser_context_t *c, pd_TssServerURL_t *v);
parser_error_t _readVecProgramInstanceTMaxProgramHashes(parser_context_t *c, pd_VecProgramInstanceTMaxProgramHashes_t *v);
parser_error_t _readX25519PublicKey(parser_context_t *c, pd_X25519PublicKey_t *v);
parser_error_t _readBoundedVecProgramInstanceTMaxProgramHashes(parser_context_t *c,
                                                               pd_BoundedVecProgramInstanceTMaxProgramHashes_t *v);
parser_error_t _readBoxPalletsOrigin(parser_context_t *c, pd_BoxPalletsOrigin_t *v);
parser_error_t _readConfigOpBalanceOfT(parser_context_t *c, pd_ConfigOpBalanceOfT_t *v);
parser_error_t _readConfigOpPerbill(parser_context_t *c, pd_ConfigOpPerbill_t *v);
parser_error_t _readConfigOpPercent(parser_context_t *c, pd_ConfigOpPercent_t *v);
parser_error_t _readKeyVisibility(parser_context_t *c, pd_KeyVisibility_t *v);
parser_error_t _readRewardDestination(parser_context_t *c, pd_RewardDestination_t *v);
parser_error_t _readServerInfoAccountId(parser_context_t *c, pd_ServerInfoAccountId_t *v);
parser_error_t _readValidatorPrefs(parser_context_t *c, pd_ValidatorPrefs_t *v);
parser_error_t _readVecAccountIdLookupOfT(parser_context_t *c, pd_VecAccountIdLookupOfT_t *v);
parser_error_t _readVecCall(parser_context_t *c, pd_VecCall_t *v);
parser_error_t _readWeight(parser_context_t *c, pd_Weight_t *v);
parser_error_t _readAdjustmentDirection(parser_context_t *c, pd_AdjustmentDirection_t *v);
parser_error_t _readBoundedVecu8(parser_context_t *c, pd_BoundedVecu8_t *v);
parser_error_t _readCallHashOf(parser_context_t *c, pd_CallHashOf_t *v);
parser_error_t _readConfigOpu32(parser_context_t *c, pd_ConfigOpu32_t *v);
parser_error_t _readEraIndex(parser_context_t *c, pd_EraIndex_t *v);
parser_error_t _readHash(parser_context_t *c, pd_Hash_t *v);
parser_error_t _readKeys(parser_context_t *c, pd_Keys_t *v);
parser_error_t _readOptionProxyType(parser_context_t *c, pd_OptionProxyType_t *v);
parser_error_t _readPage(parser_context_t *c, pd_Page_t *v);
parser_error_t _readVecAccountId(parser_context_t *c, pd_VecAccountId_t *v);
parser_error_t _readVecu32(parser_context_t *c, pd_Vecu32_t *v);
parser_error_t _readVecu8(parser_context_t *c, pd_Vecu8_t *v);
parser_error_t _readVerifyingKey(parser_context_t *c, pd_VerifyingKey_t *v);

// Common toString functions

parser_error_t _toStringu8(const pd_u8_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringu16(const pd_u16_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringu32(const pd_u32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringu64(const pd_u64_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringbool(const pd_bool_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringBlockNumber(
    const pd_BlockNumber_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactu32(
    const pd_Compactu32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactu64(
    const pd_Compactu64_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringProgramConfig(
    const pd_ProgramConfig_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringProgramPointer(
    const pd_ProgramPointer_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringAccountId(
    const pd_AccountId_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringBytes(
    const pd_Bytes_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactAccountIndex(
    const pd_CompactAccountIndex_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringMembers(
    const pd_Members_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringProgramInstanceTMaxProgramHashes(const pd_ProgramInstanceTMaxProgramHashes_t *v,
                                                         char *outValue,
                                                         uint16_t outValueLen,
                                                         uint8_t pageIdx,
                                                         uint8_t *pageCount);

parser_error_t _toStringAccountIdLookupOfT(
    const pd_AccountIdLookupOfT_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringBalance(
    const pd_Balance_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCall(const pd_Call_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactPerBill(
    const pd_CompactPerBill_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCouncil(
    const pd_Council_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringPerbill(
    const pd_Perbill_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringPercent(
    const pd_Percent_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringProxyType(
    const pd_ProxyType_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringSystemOrigin(
    const pd_SystemOrigin_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringTssServerURL(
    const pd_TssServerURL_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecProgramInstanceTMaxProgramHashes(const pd_VecProgramInstanceTMaxProgramHashes_t *v,
                                                            char *outValue,
                                                            uint16_t outValueLen,
                                                            uint8_t pageIdx,
                                                            uint8_t *pageCount);

parser_error_t _toStringX25519PublicKey(
    const pd_X25519PublicKey_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringBoundedVecProgramInstanceTMaxProgramHashes(const pd_BoundedVecProgramInstanceTMaxProgramHashes_t *v,
                                                                   char *outValue,
                                                                   uint16_t outValueLen,
                                                                   uint8_t pageIdx,
                                                                   uint8_t *pageCount);

parser_error_t _toStringBoxPalletsOrigin(
    const pd_BoxPalletsOrigin_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringConfigOpBalanceOfT(
    const pd_ConfigOpBalanceOfT_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringConfigOpPerbill(
    const pd_ConfigOpPerbill_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringConfigOpPercent(
    const pd_ConfigOpPercent_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringKeyVisibility(
    const pd_KeyVisibility_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringRewardDestination(
    const pd_RewardDestination_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringServerInfoAccountId(
    const pd_ServerInfoAccountId_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringValidatorPrefs(
    const pd_ValidatorPrefs_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecAccountIdLookupOfT(
    const pd_VecAccountIdLookupOfT_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecCall(
    const pd_VecCall_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringWeight(
    const pd_Weight_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringAdjustmentDirection(
    const pd_AdjustmentDirection_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringBoundedVecu8(
    const pd_BoundedVecu8_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCallHashOf(
    const pd_CallHashOf_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringConfigOpu32(
    const pd_ConfigOpu32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringEraIndex(
    const pd_EraIndex_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringHash(const pd_Hash_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringKeys(const pd_Keys_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOptionProxyType(
    const pd_OptionProxyType_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringPage(const pd_Page_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecAccountId(
    const pd_VecAccountId_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecu32(
    const pd_Vecu32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecu8(
    const pd_Vecu8_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVerifyingKey(
    const pd_VerifyingKey_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

#ifdef __cplusplus
}
#endif
