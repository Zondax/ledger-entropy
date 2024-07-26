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

#include "substrate_dispatch_V7.h"

#include <stdint.h>

#include "substrate_strings.h"
#include "zxmacros.h"
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_utility_batch_V7(parser_context_t *c, pd_utility_batch_V7_t *m) {
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V7(parser_context_t *c, pd_utility_batch_all_V7_t *m) {
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V7(parser_context_t *c, pd_utility_force_batch_V7_t *m) {
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_allow_death_V7(parser_context_t *c,
                                                                       pd_balances_transfer_allow_death_V7_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V7(parser_context_t *c, pd_balances_force_transfer_V7_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V7(parser_context_t *c,
                                                                      pd_balances_transfer_keep_alive_V7_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V7(parser_context_t *c, pd_balances_transfer_all_V7_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V7(parser_context_t *c, pd_staking_bond_V7_t *m) {
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V7(parser_context_t *c, pd_staking_bond_extra_V7_t *m) {
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V7(parser_context_t *c, pd_staking_unbond_V7_t *m) {
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V7(parser_context_t *c,
                                                                   pd_staking_withdraw_unbonded_V7_t *m) {
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V7(parser_context_t *c, pd_staking_validate_V7_t *m) {
    CHECK_ERROR(_readValidatorPrefs(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V7(parser_context_t *c, pd_staking_nominate_V7_t *m) {
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V7(parser_context_t *c, pd_staking_chill_V7_t *m) {
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V7(parser_context_t *c, pd_staking_set_payee_V7_t *m) {
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V7(parser_context_t *c, pd_staking_set_controller_V7_t *m) {
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V7(parser_context_t *c, pd_staking_payout_stakers_V7_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V7(parser_context_t *c, pd_staking_rebond_V7_t *m) {
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V7(parser_context_t *c, pd_session_set_keys_V7_t *m) {
    CHECK_ERROR(_readKeys(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V7(parser_context_t *c, pd_session_purge_keys_V7_t *m) {
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
__Z_INLINE parser_error_t _readMethod_system_remark_V7(parser_context_t *c, pd_system_remark_V7_t *m) {
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V7(parser_context_t *c, pd_system_set_heap_pages_V7_t *m) {
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V7(parser_context_t *c, pd_system_set_code_V7_t *m) {
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V7(parser_context_t *c,
                                                                        pd_system_set_code_without_checks_V7_t *m) {
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V7(parser_context_t *c, pd_system_remark_with_event_V7_t *m) {
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_authorize_upgrade_V7(parser_context_t *c, pd_system_authorize_upgrade_V7_t *m) {
    CHECK_ERROR(_readHash(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_authorize_upgrade_without_checks_V7(
    parser_context_t *c, pd_system_authorize_upgrade_without_checks_V7_t *m) {
    CHECK_ERROR(_readHash(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_apply_authorized_upgrade_V7(parser_context_t *c,
                                                                         pd_system_apply_authorized_upgrade_V7_t *m) {
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_dispatch_as_V7(parser_context_t *c, pd_utility_dispatch_as_V7_t *m) {
    CHECK_ERROR(_readBoxPalletsOrigin(c, &m->as_origin))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_with_weight_V7(parser_context_t *c, pd_utility_with_weight_V7_t *m) {
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V7(parser_context_t *c, pd_balances_force_unreserve_V7_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_upgrade_accounts_V7(parser_context_t *c,
                                                                   pd_balances_upgrade_accounts_V7_t *m) {
    CHECK_ERROR(_readVecAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_set_balance_V7(parser_context_t *c,
                                                                    pd_balances_force_set_balance_V7_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_balances_force_adjust_total_issuance_V7(parser_context_t *c, pd_balances_force_adjust_total_issuance_V7_t *m) {
    CHECK_ERROR(_readAdjustmentDirection(c, &m->direction))
    CHECK_ERROR(_readCompactBalance(c, &m->delta))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V7(parser_context_t *c,
                                                                     pd_staking_set_validator_count_V7_t *m) {
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V7(parser_context_t *c,
                                                                          pd_staking_increase_validator_count_V7_t *m) {
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V7(parser_context_t *c,
                                                                       pd_staking_scale_validator_count_V7_t *m) {
    CHECK_ERROR(_readPercent(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V7(parser_context_t *c, pd_staking_force_no_eras_V7_t *m) {
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V7(parser_context_t *c, pd_staking_force_new_era_V7_t *m) {
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V7(parser_context_t *c,
                                                                   pd_staking_set_invulnerables_V7_t *m) {
    CHECK_ERROR(_readVecAccountId(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V7(parser_context_t *c, pd_staking_force_unstake_V7_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V7(parser_context_t *c,
                                                                      pd_staking_force_new_era_always_V7_t *m) {
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V7(parser_context_t *c,
                                                                       pd_staking_cancel_deferred_slash_V7_t *m) {
    CHECK_ERROR(_readEraIndex(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V7(parser_context_t *c, pd_staking_reap_stash_V7_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V7(parser_context_t *c, pd_staking_kick_V7_t *m) {
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_staking_configs_V7(parser_context_t *c,
                                                                     pd_staking_set_staking_configs_V7_t *m) {
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_nominator_bond))
    CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_validator_bond))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_nominator_count))
    CHECK_ERROR(_readConfigOpu32(c, &m->max_validator_count))
    CHECK_ERROR(_readConfigOpPercent(c, &m->chill_threshold))
    CHECK_ERROR(_readConfigOpPerbill(c, &m->min_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_other_V7(parser_context_t *c, pd_staking_chill_other_V7_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->stash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_apply_min_commission_V7(parser_context_t *c,
                                                                            pd_staking_force_apply_min_commission_V7_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_min_commission_V7(parser_context_t *c,
                                                                    pd_staking_set_min_commission_V7_t *m) {
    CHECK_ERROR(_readPerbill(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_by_page_V7(parser_context_t *c,
                                                                        pd_staking_payout_stakers_by_page_V7_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    CHECK_ERROR(_readPage(c, &m->page))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_update_payee_V7(parser_context_t *c, pd_staking_update_payee_V7_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_restore_ledger_V7(parser_context_t *c, pd_staking_restore_ledger_V7_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readOptionAccountId(c, &m->maybe_controller))
    CHECK_ERROR(_readOptionBalance(c, &m->maybe_total))
    CHECK_ERROR(_readOptionBoundedVecUnlockChunkBalanceOfTMaxUnlockingChunks(c, &m->maybe_unlocking))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stakingextension_change_endpoint_V7(parser_context_t *c,
                                                                          pd_stakingextension_change_endpoint_V7_t *m) {
    CHECK_ERROR(_readVecu8(c, &m->endpoint))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stakingextension_change_threshold_accounts_V7(
    parser_context_t *c, pd_stakingextension_change_threshold_accounts_V7_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->tss_account))
    CHECK_ERROR(_readX25519PublicKey(c, &m->x25519_public_key))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stakingextension_withdraw_unbonded_V7(parser_context_t *c,
                                                                            pd_stakingextension_withdraw_unbonded_V7_t *m) {
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stakingextension_validate_V7(parser_context_t *c,
                                                                   pd_stakingextension_validate_V7_t *m) {
    CHECK_ERROR(_readValidatorPrefs(c, &m->prefs))
    CHECK_ERROR(_readServerInfoAccountId(c, &m->server_info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stakingextension_declare_synced_V7(parser_context_t *c,
                                                                         pd_stakingextension_declare_synced_V7_t *m) {
    CHECK_ERROR(_readbool(c, &m->synced))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V7(parser_context_t *c, pd_proxy_proxy_V7_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readOptionProxyType(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V7(parser_context_t *c, pd_proxy_add_proxy_V7_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V7(parser_context_t *c, pd_proxy_remove_proxy_V7_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V7(parser_context_t *c, pd_proxy_remove_proxies_V7_t *m) {
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_create_pure_V7(parser_context_t *c, pd_proxy_create_pure_V7_t *m) {
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_pure_V7(parser_context_t *c, pd_proxy_kill_pure_V7_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->spawner))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactu32(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_announce_V7(parser_context_t *c, pd_proxy_announce_V7_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readCallHashOf(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_announcement_V7(parser_context_t *c,
                                                                   pd_proxy_remove_announcement_V7_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readCallHashOf(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_reject_announcement_V7(parser_context_t *c,
                                                                   pd_proxy_reject_announcement_V7_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readCallHashOf(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V7(parser_context_t *c, pd_proxy_proxy_announced_V7_t *m) {
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readOptionProxyType(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registry_register_V7(parser_context_t *c, pd_registry_register_V7_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->program_modification_account))
    CHECK_ERROR(_readKeyVisibility(c, &m->key_visibility))
    CHECK_ERROR(_readBoundedVecProgramInstanceTMaxProgramHashes(c, &m->programs_data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registry_prune_registration_V7(parser_context_t *c,
                                                                     pd_registry_prune_registration_V7_t *m) {
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registry_change_program_instance_V7(parser_context_t *c,
                                                                          pd_registry_change_program_instance_V7_t *m) {
    CHECK_ERROR(_readVerifyingKey(c, &m->verifying_key))
    CHECK_ERROR(_readBoundedVecProgramInstanceTMaxProgramHashes(c, &m->new_program_instance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registry_change_program_modification_account_V7(
    parser_context_t *c, pd_registry_change_program_modification_account_V7_t *m) {
    CHECK_ERROR(_readVerifyingKey(c, &m->verifying_key))
    CHECK_ERROR(_readAccountId(c, &m->new_program_mod_account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registry_confirm_register_V7(parser_context_t *c,
                                                                   pd_registry_confirm_register_V7_t *m) {
    CHECK_ERROR(_readAccountId(c, &m->sig_req_account))
    CHECK_ERROR(_readu8(c, &m->signing_subgroup))
    CHECK_ERROR(_readBoundedVecu8(c, &m->verifying_key))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_programs_set_program_V7(parser_context_t *c, pd_programs_set_program_V7_t *m) {
    CHECK_ERROR(_readVecu8(c, &m->new_program))
    CHECK_ERROR(_readVecu8(c, &m->configuration_schema))
    CHECK_ERROR(_readVecu8(c, &m->auxiliary_data_schema))
    CHECK_ERROR(_readVecu8(c, &m->oracle_data_pointer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_programs_remove_program_V7(parser_context_t *c, pd_programs_remove_program_V7_t *m) {
    CHECK_ERROR(_readHash(c, &m->program_hash))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V7(parser_context_t *c, uint8_t moduleIdx, uint8_t callIdx, pd_Method_V7_t *method) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 512: /* module 2 call 0 */
            CHECK_ERROR(_readMethod_utility_batch_V7(c, &method->basic.utility_batch_V7))
            break;
        case 514: /* module 2 call 2 */
            CHECK_ERROR(_readMethod_utility_batch_all_V7(c, &method->basic.utility_batch_all_V7))
            break;
        case 516: /* module 2 call 4 */
            CHECK_ERROR(_readMethod_utility_force_batch_V7(c, &method->basic.utility_force_batch_V7))
            break;
        case 1792: /* module 7 call 0 */
            CHECK_ERROR(_readMethod_balances_transfer_allow_death_V7(c, &method->nested.balances_transfer_allow_death_V7))
            break;
        case 1794: /* module 7 call 2 */
            CHECK_ERROR(_readMethod_balances_force_transfer_V7(c, &method->nested.balances_force_transfer_V7))
            break;
        case 1795: /* module 7 call 3 */
            CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V7(c, &method->nested.balances_transfer_keep_alive_V7))
            break;
        case 1796: /* module 7 call 4 */
            CHECK_ERROR(_readMethod_balances_transfer_all_V7(c, &method->nested.balances_transfer_all_V7))
            break;
        case 2816: /* module 11 call 0 */
            CHECK_ERROR(_readMethod_staking_bond_V7(c, &method->nested.staking_bond_V7))
            break;
        case 2817: /* module 11 call 1 */
            CHECK_ERROR(_readMethod_staking_bond_extra_V7(c, &method->nested.staking_bond_extra_V7))
            break;
        case 2818: /* module 11 call 2 */
            CHECK_ERROR(_readMethod_staking_unbond_V7(c, &method->nested.staking_unbond_V7))
            break;
        case 2819: /* module 11 call 3 */
            CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V7(c, &method->nested.staking_withdraw_unbonded_V7))
            break;
        case 2820: /* module 11 call 4 */
            CHECK_ERROR(_readMethod_staking_validate_V7(c, &method->nested.staking_validate_V7))
            break;
        case 2821: /* module 11 call 5 */
            CHECK_ERROR(_readMethod_staking_nominate_V7(c, &method->nested.staking_nominate_V7))
            break;
        case 2822: /* module 11 call 6 */
            CHECK_ERROR(_readMethod_staking_chill_V7(c, &method->nested.staking_chill_V7))
            break;
        case 2823: /* module 11 call 7 */
            CHECK_ERROR(_readMethod_staking_set_payee_V7(c, &method->nested.staking_set_payee_V7))
            break;
        case 2824: /* module 11 call 8 */
            CHECK_ERROR(_readMethod_staking_set_controller_V7(c, &method->nested.staking_set_controller_V7))
            break;
        case 2834: /* module 11 call 18 */
            CHECK_ERROR(_readMethod_staking_payout_stakers_V7(c, &method->nested.staking_payout_stakers_V7))
            break;
        case 2835: /* module 11 call 19 */
            CHECK_ERROR(_readMethod_staking_rebond_V7(c, &method->nested.staking_rebond_V7))
            break;
        case 5120: /* module 20 call 0 */
            CHECK_ERROR(_readMethod_session_set_keys_V7(c, &method->nested.session_set_keys_V7))
            break;
        case 5121: /* module 20 call 1 */
            CHECK_ERROR(_readMethod_session_purge_keys_V7(c, &method->nested.session_purge_keys_V7))
            break;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
        case 256: /* module 1 call 0 */
            CHECK_ERROR(_readMethod_system_remark_V7(c, &method->nested.system_remark_V7))
            break;
        case 257: /* module 1 call 1 */
            CHECK_ERROR(_readMethod_system_set_heap_pages_V7(c, &method->nested.system_set_heap_pages_V7))
            break;
        case 258: /* module 1 call 2 */
            CHECK_ERROR(_readMethod_system_set_code_V7(c, &method->nested.system_set_code_V7))
            break;
        case 259: /* module 1 call 3 */
            CHECK_ERROR(_readMethod_system_set_code_without_checks_V7(c, &method->nested.system_set_code_without_checks_V7))
            break;
        case 263: /* module 1 call 7 */
            CHECK_ERROR(_readMethod_system_remark_with_event_V7(c, &method->nested.system_remark_with_event_V7))
            break;
        case 265: /* module 1 call 9 */
            CHECK_ERROR(_readMethod_system_authorize_upgrade_V7(c, &method->basic.system_authorize_upgrade_V7))
            break;
        case 266: /* module 1 call 10 */
            CHECK_ERROR(
                _readMethod_system_authorize_upgrade_without_checks_V7(c, &method->basic
                                                                               .system_authorize_upgrade_without_checks_V7))
            break;
        case 267: /* module 1 call 11 */
            CHECK_ERROR(_readMethod_system_apply_authorized_upgrade_V7(c, &method->basic.system_apply_authorized_upgrade_V7))
            break;
        case 515: /* module 2 call 3 */
            CHECK_ERROR(_readMethod_utility_dispatch_as_V7(c, &method->basic.utility_dispatch_as_V7))
            break;
        case 517: /* module 2 call 5 */
            CHECK_ERROR(_readMethod_utility_with_weight_V7(c, &method->basic.utility_with_weight_V7))
            break;
        case 1797: /* module 7 call 5 */
            CHECK_ERROR(_readMethod_balances_force_unreserve_V7(c, &method->basic.balances_force_unreserve_V7))
            break;
        case 1798: /* module 7 call 6 */
            CHECK_ERROR(_readMethod_balances_upgrade_accounts_V7(c, &method->basic.balances_upgrade_accounts_V7))
            break;
        case 1800: /* module 7 call 8 */
            CHECK_ERROR(_readMethod_balances_force_set_balance_V7(c, &method->basic.balances_force_set_balance_V7))
            break;
        case 1801: /* module 7 call 9 */
            CHECK_ERROR(
                _readMethod_balances_force_adjust_total_issuance_V7(c,
                                                                    &method->basic.balances_force_adjust_total_issuance_V7))
            break;
        case 2825: /* module 11 call 9 */
            CHECK_ERROR(_readMethod_staking_set_validator_count_V7(c, &method->basic.staking_set_validator_count_V7))
            break;
        case 2826: /* module 11 call 10 */
            CHECK_ERROR(
                _readMethod_staking_increase_validator_count_V7(c, &method->basic.staking_increase_validator_count_V7))
            break;
        case 2827: /* module 11 call 11 */
            CHECK_ERROR(_readMethod_staking_scale_validator_count_V7(c, &method->basic.staking_scale_validator_count_V7))
            break;
        case 2828: /* module 11 call 12 */
            CHECK_ERROR(_readMethod_staking_force_no_eras_V7(c, &method->basic.staking_force_no_eras_V7))
            break;
        case 2829: /* module 11 call 13 */
            CHECK_ERROR(_readMethod_staking_force_new_era_V7(c, &method->basic.staking_force_new_era_V7))
            break;
        case 2830: /* module 11 call 14 */
            CHECK_ERROR(_readMethod_staking_set_invulnerables_V7(c, &method->basic.staking_set_invulnerables_V7))
            break;
        case 2831: /* module 11 call 15 */
            CHECK_ERROR(_readMethod_staking_force_unstake_V7(c, &method->basic.staking_force_unstake_V7))
            break;
        case 2832: /* module 11 call 16 */
            CHECK_ERROR(_readMethod_staking_force_new_era_always_V7(c, &method->basic.staking_force_new_era_always_V7))
            break;
        case 2833: /* module 11 call 17 */
            CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V7(c, &method->basic.staking_cancel_deferred_slash_V7))
            break;
        case 2836: /* module 11 call 20 */
            CHECK_ERROR(_readMethod_staking_reap_stash_V7(c, &method->basic.staking_reap_stash_V7))
            break;
        case 2837: /* module 11 call 21 */
            CHECK_ERROR(_readMethod_staking_kick_V7(c, &method->basic.staking_kick_V7))
            break;
        case 2838: /* module 11 call 22 */
            CHECK_ERROR(_readMethod_staking_set_staking_configs_V7(c, &method->basic.staking_set_staking_configs_V7))
            break;
        case 2839: /* module 11 call 23 */
            CHECK_ERROR(_readMethod_staking_chill_other_V7(c, &method->basic.staking_chill_other_V7))
            break;
        case 2840: /* module 11 call 24 */
            CHECK_ERROR(
                _readMethod_staking_force_apply_min_commission_V7(c, &method->basic.staking_force_apply_min_commission_V7))
            break;
        case 2841: /* module 11 call 25 */
            CHECK_ERROR(_readMethod_staking_set_min_commission_V7(c, &method->basic.staking_set_min_commission_V7))
            break;
        case 2842: /* module 11 call 26 */
            CHECK_ERROR(_readMethod_staking_payout_stakers_by_page_V7(c, &method->basic.staking_payout_stakers_by_page_V7))
            break;
        case 2843: /* module 11 call 27 */
            CHECK_ERROR(_readMethod_staking_update_payee_V7(c, &method->basic.staking_update_payee_V7))
            break;
        case 2845: /* module 11 call 29 */
            CHECK_ERROR(_readMethod_staking_restore_ledger_V7(c, &method->basic.staking_restore_ledger_V7))
            break;
        case 3072: /* module 12 call 0 */
            CHECK_ERROR(
                _readMethod_stakingextension_change_endpoint_V7(c, &method->basic.stakingextension_change_endpoint_V7))
            break;
        case 3073: /* module 12 call 1 */
            CHECK_ERROR(_readMethod_stakingextension_change_threshold_accounts_V7(
                c, &method->basic.stakingextension_change_threshold_accounts_V7))
            break;
        case 3074: /* module 12 call 2 */
            CHECK_ERROR(
                _readMethod_stakingextension_withdraw_unbonded_V7(c, &method->basic.stakingextension_withdraw_unbonded_V7))
            break;
        case 3075: /* module 12 call 3 */
            CHECK_ERROR(_readMethod_stakingextension_validate_V7(c, &method->basic.stakingextension_validate_V7))
            break;
        case 3076: /* module 12 call 4 */
            CHECK_ERROR(_readMethod_stakingextension_declare_synced_V7(c, &method->basic.stakingextension_declare_synced_V7))
            break;
        case 11264: /* module 44 call 0 */
            CHECK_ERROR(_readMethod_proxy_proxy_V7(c, &method->nested.proxy_proxy_V7))
            break;
        case 11265: /* module 44 call 1 */
            CHECK_ERROR(_readMethod_proxy_add_proxy_V7(c, &method->nested.proxy_add_proxy_V7))
            break;
        case 11266: /* module 44 call 2 */
            CHECK_ERROR(_readMethod_proxy_remove_proxy_V7(c, &method->nested.proxy_remove_proxy_V7))
            break;
        case 11267: /* module 44 call 3 */
            CHECK_ERROR(_readMethod_proxy_remove_proxies_V7(c, &method->basic.proxy_remove_proxies_V7))
            break;
        case 11268: /* module 44 call 4 */
            CHECK_ERROR(_readMethod_proxy_create_pure_V7(c, &method->nested.proxy_create_pure_V7))
            break;
        case 11269: /* module 44 call 5 */
            CHECK_ERROR(_readMethod_proxy_kill_pure_V7(c, &method->nested.proxy_kill_pure_V7))
            break;
        case 11270: /* module 44 call 6 */
            CHECK_ERROR(_readMethod_proxy_announce_V7(c, &method->basic.proxy_announce_V7))
            break;
        case 11271: /* module 44 call 7 */
            CHECK_ERROR(_readMethod_proxy_remove_announcement_V7(c, &method->basic.proxy_remove_announcement_V7))
            break;
        case 11272: /* module 44 call 8 */
            CHECK_ERROR(_readMethod_proxy_reject_announcement_V7(c, &method->basic.proxy_reject_announcement_V7))
            break;
        case 11273: /* module 44 call 9 */
            CHECK_ERROR(_readMethod_proxy_proxy_announced_V7(c, &method->basic.proxy_proxy_announced_V7))
            break;
        case 13056: /* module 51 call 0 */
            CHECK_ERROR(_readMethod_registry_register_V7(c, &method->basic.registry_register_V7))
            break;
        case 13057: /* module 51 call 1 */
            CHECK_ERROR(_readMethod_registry_prune_registration_V7(c, &method->basic.registry_prune_registration_V7))
            break;
        case 13058: /* module 51 call 2 */
            CHECK_ERROR(
                _readMethod_registry_change_program_instance_V7(c, &method->basic.registry_change_program_instance_V7))
            break;
        case 13059: /* module 51 call 3 */
            CHECK_ERROR(_readMethod_registry_change_program_modification_account_V7(
                c, &method->basic.registry_change_program_modification_account_V7))
            break;
        case 13060: /* module 51 call 4 */
            CHECK_ERROR(_readMethod_registry_confirm_register_V7(c, &method->basic.registry_confirm_register_V7))
            break;
        case 13568: /* module 53 call 0 */
            CHECK_ERROR(_readMethod_programs_set_program_V7(c, &method->basic.programs_set_program_V7))
            break;
        case 13569: /* module 53 call 1 */
            CHECK_ERROR(_readMethod_programs_remove_program_V7(c, &method->basic.programs_remove_program_V7))
            break;
#endif
        default:
            return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char *_getMethod_ModuleName_V7(uint8_t moduleIdx) {
    switch (moduleIdx) {
        case 2:
            return STR_MO_UTILITY;
        case 7:
            return STR_MO_BALANCES;
        case 11:
            return STR_MO_STAKING;
        case 20:
            return STR_MO_SESSION;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
        case 1:
            return STR_MO_SYSTEM;
        case 12:
            return STR_MO_STAKINGEXTENSION;
        case 44:
            return STR_MO_PROXY;
        case 51:
            return STR_MO_REGISTRY;
        case 53:
            return STR_MO_PROGRAMS;
#endif
        default:
            return NULL;
    }

    return NULL;
}

const char *_getMethod_Name_V7(uint8_t moduleIdx, uint8_t callIdx) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 512: /* module 2 call 0 */
            return STR_ME_BATCH;
        case 514: /* module 2 call 2 */
            return STR_ME_BATCH_ALL;
        case 516: /* module 2 call 4 */
            return STR_ME_FORCE_BATCH;
        case 1792: /* module 7 call 0 */
            return STR_ME_TRANSFER_ALLOW_DEATH;
        case 1794: /* module 7 call 2 */
            return STR_ME_FORCE_TRANSFER;
        case 1795: /* module 7 call 3 */
            return STR_ME_TRANSFER_KEEP_ALIVE;
        case 1796: /* module 7 call 4 */
            return STR_ME_TRANSFER_ALL;
        case 2816: /* module 11 call 0 */
            return STR_ME_BOND;
        case 2817: /* module 11 call 1 */
            return STR_ME_BOND_EXTRA;
        case 2818: /* module 11 call 2 */
            return STR_ME_UNBOND;
        case 2819: /* module 11 call 3 */
            return STR_ME_WITHDRAW_UNBONDED;
        case 2820: /* module 11 call 4 */
            return STR_ME_VALIDATE;
        case 2821: /* module 11 call 5 */
            return STR_ME_NOMINATE;
        case 2822: /* module 11 call 6 */
            return STR_ME_CHILL;
        case 2823: /* module 11 call 7 */
            return STR_ME_SET_PAYEE;
        case 2824: /* module 11 call 8 */
            return STR_ME_SET_CONTROLLER;
        case 2834: /* module 11 call 18 */
            return STR_ME_PAYOUT_STAKERS;
        case 2835: /* module 11 call 19 */
            return STR_ME_REBOND;
        case 5120: /* module 20 call 0 */
            return STR_ME_SET_KEYS;
        case 5121: /* module 20 call 1 */
            return STR_ME_PURGE_KEYS;
        default:
            return _getMethod_Name_V7_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char *_getMethod_Name_V7_ParserFull(uint16_t callPrivIdx) {
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
        case 256: /* module 1 call 0 */
            return STR_ME_REMARK;
        case 257: /* module 1 call 1 */
            return STR_ME_SET_HEAP_PAGES;
        case 258: /* module 1 call 2 */
            return STR_ME_SET_CODE;
        case 259: /* module 1 call 3 */
            return STR_ME_SET_CODE_WITHOUT_CHECKS;
        case 263: /* module 1 call 7 */
            return STR_ME_REMARK_WITH_EVENT;
        case 265: /* module 1 call 9 */
            return STR_ME_AUTHORIZE_UPGRADE;
        case 266: /* module 1 call 10 */
            return STR_ME_AUTHORIZE_UPGRADE_WITHOUT_CHECKS;
        case 267: /* module 1 call 11 */
            return STR_ME_APPLY_AUTHORIZED_UPGRADE;
        case 515: /* module 2 call 3 */
            return STR_ME_DISPATCH_AS;
        case 517: /* module 2 call 5 */
            return STR_ME_WITH_WEIGHT;
        case 1797: /* module 7 call 5 */
            return STR_ME_FORCE_UNRESERVE;
        case 1798: /* module 7 call 6 */
            return STR_ME_UPGRADE_ACCOUNTS;
        case 1800: /* module 7 call 8 */
            return STR_ME_FORCE_SET_BALANCE;
        case 1801: /* module 7 call 9 */
            return STR_ME_FORCE_ADJUST_TOTAL_ISSUANCE;
        case 2825: /* module 11 call 9 */
            return STR_ME_SET_VALIDATOR_COUNT;
        case 2826: /* module 11 call 10 */
            return STR_ME_INCREASE_VALIDATOR_COUNT;
        case 2827: /* module 11 call 11 */
            return STR_ME_SCALE_VALIDATOR_COUNT;
        case 2828: /* module 11 call 12 */
            return STR_ME_FORCE_NO_ERAS;
        case 2829: /* module 11 call 13 */
            return STR_ME_FORCE_NEW_ERA;
        case 2830: /* module 11 call 14 */
            return STR_ME_SET_INVULNERABLES;
        case 2831: /* module 11 call 15 */
            return STR_ME_FORCE_UNSTAKE;
        case 2832: /* module 11 call 16 */
            return STR_ME_FORCE_NEW_ERA_ALWAYS;
        case 2833: /* module 11 call 17 */
            return STR_ME_CANCEL_DEFERRED_SLASH;
        case 2836: /* module 11 call 20 */
            return STR_ME_REAP_STASH;
        case 2837: /* module 11 call 21 */
            return STR_ME_KICK;
        case 2838: /* module 11 call 22 */
            return STR_ME_SET_STAKING_CONFIGS;
        case 2839: /* module 11 call 23 */
            return STR_ME_CHILL_OTHER;
        case 2840: /* module 11 call 24 */
            return STR_ME_FORCE_APPLY_MIN_COMMISSION;
        case 2841: /* module 11 call 25 */
            return STR_ME_SET_MIN_COMMISSION;
        case 2842: /* module 11 call 26 */
            return STR_ME_PAYOUT_STAKERS_BY_PAGE;
        case 2843: /* module 11 call 27 */
            return STR_ME_UPDATE_PAYEE;
        case 2845: /* module 11 call 29 */
            return STR_ME_RESTORE_LEDGER;
        case 3072: /* module 12 call 0 */
            return STR_ME_CHANGE_ENDPOINT;
        case 3073: /* module 12 call 1 */
            return STR_ME_CHANGE_THRESHOLD_ACCOUNTS;
        case 3074: /* module 12 call 2 */
            return STR_ME_WITHDRAW_UNBONDED;
        case 3075: /* module 12 call 3 */
            return STR_ME_VALIDATE;
        case 3076: /* module 12 call 4 */
            return STR_ME_DECLARE_SYNCED;
        case 11264: /* module 44 call 0 */
            return STR_ME_PROXY;
        case 11265: /* module 44 call 1 */
            return STR_ME_ADD_PROXY;
        case 11266: /* module 44 call 2 */
            return STR_ME_REMOVE_PROXY;
        case 11267: /* module 44 call 3 */
            return STR_ME_REMOVE_PROXIES;
        case 11268: /* module 44 call 4 */
            return STR_ME_CREATE_PURE;
        case 11269: /* module 44 call 5 */
            return STR_ME_KILL_PURE;
        case 11270: /* module 44 call 6 */
            return STR_ME_ANNOUNCE;
        case 11271: /* module 44 call 7 */
            return STR_ME_REMOVE_ANNOUNCEMENT;
        case 11272: /* module 44 call 8 */
            return STR_ME_REJECT_ANNOUNCEMENT;
        case 11273: /* module 44 call 9 */
            return STR_ME_PROXY_ANNOUNCED;
        case 13056: /* module 51 call 0 */
            return STR_ME_REGISTER;
        case 13057: /* module 51 call 1 */
            return STR_ME_PRUNE_REGISTRATION;
        case 13058: /* module 51 call 2 */
            return STR_ME_CHANGE_PROGRAM_INSTANCE;
        case 13059: /* module 51 call 3 */
            return STR_ME_CHANGE_PROGRAM_MODIFICATION_ACCOUNT;
        case 13060: /* module 51 call 4 */
            return STR_ME_CONFIRM_REGISTER;
        case 13568: /* module 53 call 0 */
            return STR_ME_SET_PROGRAM;
        case 13569: /* module 53 call 1 */
            return STR_ME_REMOVE_PROGRAM;
#endif
        default:
            return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V7(uint8_t moduleIdx, uint8_t callIdx) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 512: /* module 2 call 0 */
            return 1;
        case 514: /* module 2 call 2 */
            return 1;
        case 516: /* module 2 call 4 */
            return 1;
        case 1792: /* module 7 call 0 */
            return 2;
        case 1794: /* module 7 call 2 */
            return 3;
        case 1795: /* module 7 call 3 */
            return 2;
        case 1796: /* module 7 call 4 */
            return 2;
        case 2816: /* module 11 call 0 */
            return 2;
        case 2817: /* module 11 call 1 */
            return 1;
        case 2818: /* module 11 call 2 */
            return 1;
        case 2819: /* module 11 call 3 */
            return 1;
        case 2820: /* module 11 call 4 */
            return 1;
        case 2821: /* module 11 call 5 */
            return 1;
        case 2822: /* module 11 call 6 */
            return 0;
        case 2823: /* module 11 call 7 */
            return 1;
        case 2824: /* module 11 call 8 */
            return 0;
        case 2834: /* module 11 call 18 */
            return 2;
        case 2835: /* module 11 call 19 */
            return 1;
        case 5120: /* module 20 call 0 */
            return 2;
        case 5121: /* module 20 call 1 */
            return 0;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
        case 256: /* module 1 call 0 */
            return 1;
        case 257: /* module 1 call 1 */
            return 1;
        case 258: /* module 1 call 2 */
            return 1;
        case 259: /* module 1 call 3 */
            return 1;
        case 263: /* module 1 call 7 */
            return 1;
        case 265: /* module 1 call 9 */
            return 1;
        case 266: /* module 1 call 10 */
            return 1;
        case 267: /* module 1 call 11 */
            return 1;
        case 515: /* module 2 call 3 */
            return 2;
        case 517: /* module 2 call 5 */
            return 2;
        case 1797: /* module 7 call 5 */
            return 2;
        case 1798: /* module 7 call 6 */
            return 1;
        case 1800: /* module 7 call 8 */
            return 2;
        case 1801: /* module 7 call 9 */
            return 2;
        case 2825: /* module 11 call 9 */
            return 1;
        case 2826: /* module 11 call 10 */
            return 1;
        case 2827: /* module 11 call 11 */
            return 1;
        case 2828: /* module 11 call 12 */
            return 0;
        case 2829: /* module 11 call 13 */
            return 0;
        case 2830: /* module 11 call 14 */
            return 1;
        case 2831: /* module 11 call 15 */
            return 2;
        case 2832: /* module 11 call 16 */
            return 0;
        case 2833: /* module 11 call 17 */
            return 2;
        case 2836: /* module 11 call 20 */
            return 2;
        case 2837: /* module 11 call 21 */
            return 1;
        case 2838: /* module 11 call 22 */
            return 6;
        case 2839: /* module 11 call 23 */
            return 1;
        case 2840: /* module 11 call 24 */
            return 1;
        case 2841: /* module 11 call 25 */
            return 1;
        case 2842: /* module 11 call 26 */
            return 3;
        case 2843: /* module 11 call 27 */
            return 1;
        case 2845: /* module 11 call 29 */
            return 4;
        case 3072: /* module 12 call 0 */
            return 1;
        case 3073: /* module 12 call 1 */
            return 2;
        case 3074: /* module 12 call 2 */
            return 1;
        case 3075: /* module 12 call 3 */
            return 2;
        case 3076: /* module 12 call 4 */
            return 1;
        case 11264: /* module 44 call 0 */
            return 3;
        case 11265: /* module 44 call 1 */
            return 3;
        case 11266: /* module 44 call 2 */
            return 3;
        case 11267: /* module 44 call 3 */
            return 0;
        case 11268: /* module 44 call 4 */
            return 3;
        case 11269: /* module 44 call 5 */
            return 5;
        case 11270: /* module 44 call 6 */
            return 2;
        case 11271: /* module 44 call 7 */
            return 2;
        case 11272: /* module 44 call 8 */
            return 2;
        case 11273: /* module 44 call 9 */
            return 4;
        case 13056: /* module 51 call 0 */
            return 3;
        case 13057: /* module 51 call 1 */
            return 0;
        case 13058: /* module 51 call 2 */
            return 2;
        case 13059: /* module 51 call 3 */
            return 2;
        case 13060: /* module 51 call 4 */
            return 3;
        case 13568: /* module 53 call 0 */
            return 4;
        case 13569: /* module 53 call 1 */
            return 1;
#endif
        default:
            return 0;
    }

    return 0;
}

const char *_getMethod_ItemName_V7(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 512: /* module 2 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_calls;
                default:
                    return NULL;
            }
        case 514: /* module 2 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_calls;
                default:
                    return NULL;
            }
        case 516: /* module 2 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_calls;
                default:
                    return NULL;
            }
        case 1792: /* module 7 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 1794: /* module 7 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_source;
                case 1:
                    return STR_IT_dest;
                case 2:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 1795: /* module 7 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 1796: /* module 7 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_keep_alive;
                default:
                    return NULL;
            }
        case 2816: /* module 11 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                case 1:
                    return STR_IT_payee;
                default:
                    return NULL;
            }
        case 2817: /* module 11 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 2818: /* module 11 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 2819: /* module 11 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 2820: /* module 11 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_prefs;
                default:
                    return NULL;
            }
        case 2821: /* module 11 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_targets;
                default:
                    return NULL;
            }
        case 2822: /* module 11 call 6 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 2823: /* module 11 call 7 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_payee;
                default:
                    return NULL;
            }
        case 2824: /* module 11 call 8 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 2834: /* module 11 call 18 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_validator_stash;
                case 1:
                    return STR_IT_era;
                default:
                    return NULL;
            }
        case 2835: /* module 11 call 19 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 5120: /* module 20 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_keys;
                case 1:
                    return STR_IT_proof;
                default:
                    return NULL;
            }
        case 5121: /* module 20 call 1 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
        case 256: /* module 1 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_remark;
                default:
                    return NULL;
            }
        case 257: /* module 1 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pages;
                default:
                    return NULL;
            }
        case 258: /* module 1 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_code;
                default:
                    return NULL;
            }
        case 259: /* module 1 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_code;
                default:
                    return NULL;
            }
        case 263: /* module 1 call 7 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_remark;
                default:
                    return NULL;
            }
        case 265: /* module 1 call 9 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_code_hash;
                default:
                    return NULL;
            }
        case 266: /* module 1 call 10 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_code_hash;
                default:
                    return NULL;
            }
        case 267: /* module 1 call 11 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_code;
                default:
                    return NULL;
            }
        case 515: /* module 2 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_as_origin;
                case 1:
                    return STR_IT_call;
                default:
                    return NULL;
            }
        case 517: /* module 2 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_call;
                case 1:
                    return STR_IT_weight;
                default:
                    return NULL;
            }
        case 1797: /* module 7 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 1798: /* module 7 call 6 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                default:
                    return NULL;
            }
        case 1800: /* module 7 call 8 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                case 1:
                    return STR_IT_new_free;
                default:
                    return NULL;
            }
        case 1801: /* module 7 call 9 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_direction;
                case 1:
                    return STR_IT_delta;
                default:
                    return NULL;
            }
        case 2825: /* module 11 call 9 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_new_;
                default:
                    return NULL;
            }
        case 2826: /* module 11 call 10 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_additional;
                default:
                    return NULL;
            }
        case 2827: /* module 11 call 11 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_factor;
                default:
                    return NULL;
            }
        case 2828: /* module 11 call 12 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 2829: /* module 11 call 13 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 2830: /* module 11 call 14 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_invulnerables;
                default:
                    return NULL;
            }
        case 2831: /* module 11 call 15 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_stash;
                case 1:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 2832: /* module 11 call 16 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 2833: /* module 11 call 17 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_era;
                case 1:
                    return STR_IT_slash_indices;
                default:
                    return NULL;
            }
        case 2836: /* module 11 call 20 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_stash;
                case 1:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 2837: /* module 11 call 21 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                default:
                    return NULL;
            }
        case 2838: /* module 11 call 22 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_min_nominator_bond;
                case 1:
                    return STR_IT_min_validator_bond;
                case 2:
                    return STR_IT_max_nominator_count;
                case 3:
                    return STR_IT_max_validator_count;
                case 4:
                    return STR_IT_chill_threshold;
                case 5:
                    return STR_IT_min_commission;
                default:
                    return NULL;
            }
        case 2839: /* module 11 call 23 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_stash;
                default:
                    return NULL;
            }
        case 2840: /* module 11 call 24 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_validator_stash;
                default:
                    return NULL;
            }
        case 2841: /* module 11 call 25 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_new_;
                default:
                    return NULL;
            }
        case 2842: /* module 11 call 26 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_validator_stash;
                case 1:
                    return STR_IT_era;
                case 2:
                    return STR_IT_page;
                default:
                    return NULL;
            }
        case 2843: /* module 11 call 27 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_controller;
                default:
                    return NULL;
            }
        case 2845: /* module 11 call 29 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_stash;
                case 1:
                    return STR_IT_maybe_controller;
                case 2:
                    return STR_IT_maybe_total;
                case 3:
                    return STR_IT_maybe_unlocking;
                default:
                    return NULL;
            }
        case 3072: /* module 12 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_endpoint;
                default:
                    return NULL;
            }
        case 3073: /* module 12 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_tss_account;
                case 1:
                    return STR_IT_x25519_public_key;
                default:
                    return NULL;
            }
        case 3074: /* module 12 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 3075: /* module 12 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_prefs;
                case 1:
                    return STR_IT_server_info;
                default:
                    return NULL;
            }
        case 3076: /* module 12 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_synced;
                default:
                    return NULL;
            }
        case 11264: /* module 44 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_real;
                case 1:
                    return STR_IT_force_proxy_type;
                case 2:
                    return STR_IT_call;
                default:
                    return NULL;
            }
        case 11265: /* module 44 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_delegate;
                case 1:
                    return STR_IT_proxy_type;
                case 2:
                    return STR_IT_delay;
                default:
                    return NULL;
            }
        case 11266: /* module 44 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_delegate;
                case 1:
                    return STR_IT_proxy_type;
                case 2:
                    return STR_IT_delay;
                default:
                    return NULL;
            }
        case 11267: /* module 44 call 3 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 11268: /* module 44 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_proxy_type;
                case 1:
                    return STR_IT_delay;
                case 2:
                    return STR_IT_index;
                default:
                    return NULL;
            }
        case 11269: /* module 44 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_spawner;
                case 1:
                    return STR_IT_proxy_type;
                case 2:
                    return STR_IT_index;
                case 3:
                    return STR_IT_height;
                case 4:
                    return STR_IT_ext_index;
                default:
                    return NULL;
            }
        case 11270: /* module 44 call 6 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_real;
                case 1:
                    return STR_IT_call_hash;
                default:
                    return NULL;
            }
        case 11271: /* module 44 call 7 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_real;
                case 1:
                    return STR_IT_call_hash;
                default:
                    return NULL;
            }
        case 11272: /* module 44 call 8 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_delegate;
                case 1:
                    return STR_IT_call_hash;
                default:
                    return NULL;
            }
        case 11273: /* module 44 call 9 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_delegate;
                case 1:
                    return STR_IT_real;
                case 2:
                    return STR_IT_force_proxy_type;
                case 3:
                    return STR_IT_call;
                default:
                    return NULL;
            }
        case 13056: /* module 51 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_program_modification_account;
                case 1:
                    return STR_IT_key_visibility;
                case 2:
                    return STR_IT_programs_data;
                default:
                    return NULL;
            }
        case 13057: /* module 51 call 1 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 13058: /* module 51 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_verifying_key;
                case 1:
                    return STR_IT_new_program_instance;
                default:
                    return NULL;
            }
        case 13059: /* module 51 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_verifying_key;
                case 1:
                    return STR_IT_new_program_mod_account;
                default:
                    return NULL;
            }
        case 13060: /* module 51 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_sig_req_account;
                case 1:
                    return STR_IT_signing_subgroup;
                case 2:
                    return STR_IT_verifying_key;
                default:
                    return NULL;
            }
        case 13568: /* module 53 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_new_program;
                case 1:
                    return STR_IT_configuration_schema;
                case 2:
                    return STR_IT_auxiliary_data_schema;
                case 3:
                    return STR_IT_oracle_data_pointer;
                default:
                    return NULL;
            }
        case 13569: /* module 53 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_program_hash;
                default:
                    return NULL;
            }
#endif
        default:
            return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V7(pd_Method_V7_t *m,
                                       uint8_t moduleIdx,
                                       uint8_t callIdx,
                                       uint8_t itemIdx,
                                       char *outValue,
                                       uint16_t outValueLen,
                                       uint8_t pageIdx,
                                       uint8_t *pageCount) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 512: /* module 2 call 0 */
            switch (itemIdx) {
                case 0: /* utility_batch_V7 - calls */;
                    return _toStringVecCall(&m->basic.utility_batch_V7.calls, outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 514: /* module 2 call 2 */
            switch (itemIdx) {
                case 0: /* utility_batch_all_V7 - calls */;
                    return _toStringVecCall(&m->basic.utility_batch_all_V7.calls, outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 516: /* module 2 call 4 */
            switch (itemIdx) {
                case 0: /* utility_force_batch_V7 - calls */;
                    return _toStringVecCall(&m->basic.utility_force_batch_V7.calls, outValue, outValueLen, pageIdx,
                                            pageCount);
                default:
                    return parser_no_data;
            }
        case 1792: /* module 7 call 0 */
            switch (itemIdx) {
                case 0: /* balances_transfer_allow_death_V7 - dest */;
                    return _toStringAccountIdLookupOfT(&m->nested.balances_transfer_allow_death_V7.dest, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 1: /* balances_transfer_allow_death_V7 - amount */;
                    return _toStringCompactBalance(&m->nested.balances_transfer_allow_death_V7.amount, outValue, outValueLen,
                                                   pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1794: /* module 7 call 2 */
            switch (itemIdx) {
                case 0: /* balances_force_transfer_V7 - source */;
                    return _toStringAccountIdLookupOfT(&m->nested.balances_force_transfer_V7.source, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 1: /* balances_force_transfer_V7 - dest */;
                    return _toStringAccountIdLookupOfT(&m->nested.balances_force_transfer_V7.dest, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 2: /* balances_force_transfer_V7 - amount */;
                    return _toStringCompactBalance(&m->nested.balances_force_transfer_V7.amount, outValue, outValueLen,
                                                   pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1795: /* module 7 call 3 */
            switch (itemIdx) {
                case 0: /* balances_transfer_keep_alive_V7 - dest */;
                    return _toStringAccountIdLookupOfT(&m->nested.balances_transfer_keep_alive_V7.dest, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 1: /* balances_transfer_keep_alive_V7 - amount */;
                    return _toStringCompactBalance(&m->nested.balances_transfer_keep_alive_V7.amount, outValue, outValueLen,
                                                   pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1796: /* module 7 call 4 */
            switch (itemIdx) {
                case 0: /* balances_transfer_all_V7 - dest */;
                    return _toStringAccountIdLookupOfT(&m->nested.balances_transfer_all_V7.dest, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 1: /* balances_transfer_all_V7 - keep_alive */;
                    return _toStringbool(&m->nested.balances_transfer_all_V7.keep_alive, outValue, outValueLen, pageIdx,
                                         pageCount);
                default:
                    return parser_no_data;
            }
        case 2816: /* module 11 call 0 */
            switch (itemIdx) {
                case 0: /* staking_bond_V7 - amount */;
                    return _toStringCompactBalance(&m->nested.staking_bond_V7.amount, outValue, outValueLen, pageIdx,
                                                   pageCount);
                case 1: /* staking_bond_V7 - payee */;
                    return _toStringRewardDestination(&m->nested.staking_bond_V7.payee, outValue, outValueLen, pageIdx,
                                                      pageCount);
                default:
                    return parser_no_data;
            }
        case 2817: /* module 11 call 1 */
            switch (itemIdx) {
                case 0: /* staking_bond_extra_V7 - amount */;
                    return _toStringCompactBalance(&m->nested.staking_bond_extra_V7.amount, outValue, outValueLen, pageIdx,
                                                   pageCount);
                default:
                    return parser_no_data;
            }
        case 2818: /* module 11 call 2 */
            switch (itemIdx) {
                case 0: /* staking_unbond_V7 - amount */;
                    return _toStringCompactBalance(&m->nested.staking_unbond_V7.amount, outValue, outValueLen, pageIdx,
                                                   pageCount);
                default:
                    return parser_no_data;
            }
        case 2819: /* module 11 call 3 */
            switch (itemIdx) {
                case 0: /* staking_withdraw_unbonded_V7 - num_slashing_spans */;
                    return _toStringu32(&m->nested.staking_withdraw_unbonded_V7.num_slashing_spans, outValue, outValueLen,
                                        pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2820: /* module 11 call 4 */
            switch (itemIdx) {
                case 0: /* staking_validate_V7 - prefs */;
                    return _toStringValidatorPrefs(&m->nested.staking_validate_V7.prefs, outValue, outValueLen, pageIdx,
                                                   pageCount);
                default:
                    return parser_no_data;
            }
        case 2821: /* module 11 call 5 */
            switch (itemIdx) {
                case 0: /* staking_nominate_V7 - targets */;
                    return _toStringVecAccountIdLookupOfT(&m->nested.staking_nominate_V7.targets, outValue, outValueLen,
                                                          pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2822: /* module 11 call 6 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 2823: /* module 11 call 7 */
            switch (itemIdx) {
                case 0: /* staking_set_payee_V7 - payee */;
                    return _toStringRewardDestination(&m->nested.staking_set_payee_V7.payee, outValue, outValueLen, pageIdx,
                                                      pageCount);
                default:
                    return parser_no_data;
            }
        case 2824: /* module 11 call 8 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 2834: /* module 11 call 18 */
            switch (itemIdx) {
                case 0: /* staking_payout_stakers_V7 - validator_stash */;
                    return _toStringAccountId(&m->nested.staking_payout_stakers_V7.validator_stash, outValue, outValueLen,
                                              pageIdx, pageCount);
                case 1: /* staking_payout_stakers_V7 - era */;
                    return _toStringEraIndex(&m->nested.staking_payout_stakers_V7.era, outValue, outValueLen, pageIdx,
                                             pageCount);
                default:
                    return parser_no_data;
            }
        case 2835: /* module 11 call 19 */
            switch (itemIdx) {
                case 0: /* staking_rebond_V7 - amount */;
                    return _toStringCompactBalance(&m->nested.staking_rebond_V7.amount, outValue, outValueLen, pageIdx,
                                                   pageCount);
                default:
                    return parser_no_data;
            }
        case 5120: /* module 20 call 0 */
            switch (itemIdx) {
                case 0: /* session_set_keys_V7 - keys */;
                    return _toStringKeys(&m->nested.session_set_keys_V7.keys, outValue, outValueLen, pageIdx, pageCount);
                case 1: /* session_set_keys_V7 - proof */;
                    return _toStringBytes(&m->nested.session_set_keys_V7.proof, outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 5121: /* module 20 call 1 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
        case 256: /* module 1 call 0 */
            switch (itemIdx) {
                case 0: /* system_remark_V7 - remark */;
                    return _toStringBytes(&m->nested.system_remark_V7.remark, outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 257: /* module 1 call 1 */
            switch (itemIdx) {
                case 0: /* system_set_heap_pages_V7 - pages */;
                    return _toStringu64(&m->nested.system_set_heap_pages_V7.pages, outValue, outValueLen, pageIdx,
                                        pageCount);
                default:
                    return parser_no_data;
            }
        case 258: /* module 1 call 2 */
            switch (itemIdx) {
                case 0: /* system_set_code_V7 - code */;
                    return _toStringBytes(&m->nested.system_set_code_V7.code, outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 259: /* module 1 call 3 */
            switch (itemIdx) {
                case 0: /* system_set_code_without_checks_V7 - code */;
                    return _toStringVecu8(&m->nested.system_set_code_without_checks_V7.code, outValue, outValueLen, pageIdx,
                                          pageCount);
                default:
                    return parser_no_data;
            }
        case 263: /* module 1 call 7 */
            switch (itemIdx) {
                case 0: /* system_remark_with_event_V7 - remark */;
                    return _toStringBytes(&m->nested.system_remark_with_event_V7.remark, outValue, outValueLen, pageIdx,
                                          pageCount);
                default:
                    return parser_no_data;
            }
        case 265: /* module 1 call 9 */
            switch (itemIdx) {
                case 0: /* system_authorize_upgrade_V7 - code_hash */;
                    return _toStringHash(&m->basic.system_authorize_upgrade_V7.code_hash, outValue, outValueLen, pageIdx,
                                         pageCount);
                default:
                    return parser_no_data;
            }
        case 266: /* module 1 call 10 */
            switch (itemIdx) {
                case 0: /* system_authorize_upgrade_without_checks_V7 - code_hash */;
                    return _toStringHash(&m->basic.system_authorize_upgrade_without_checks_V7.code_hash, outValue,
                                         outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 267: /* module 1 call 11 */
            switch (itemIdx) {
                case 0: /* system_apply_authorized_upgrade_V7 - code */;
                    return _toStringVecu8(&m->basic.system_apply_authorized_upgrade_V7.code, outValue, outValueLen, pageIdx,
                                          pageCount);
                default:
                    return parser_no_data;
            }
        case 515: /* module 2 call 3 */
            switch (itemIdx) {
                case 0: /* utility_dispatch_as_V7 - as_origin */;
                    return _toStringBoxPalletsOrigin(&m->basic.utility_dispatch_as_V7.as_origin, outValue, outValueLen,
                                                     pageIdx, pageCount);
                case 1: /* utility_dispatch_as_V7 - call */;
                    return _toStringCall(&m->basic.utility_dispatch_as_V7.call, outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 517: /* module 2 call 5 */
            switch (itemIdx) {
                case 0: /* utility_with_weight_V7 - call */;
                    return _toStringCall(&m->basic.utility_with_weight_V7.call, outValue, outValueLen, pageIdx, pageCount);
                case 1: /* utility_with_weight_V7 - weight */;
                    return _toStringWeight(&m->basic.utility_with_weight_V7.weight, outValue, outValueLen, pageIdx,
                                           pageCount);
                default:
                    return parser_no_data;
            }
        case 1797: /* module 7 call 5 */
            switch (itemIdx) {
                case 0: /* balances_force_unreserve_V7 - who */;
                    return _toStringAccountIdLookupOfT(&m->basic.balances_force_unreserve_V7.who, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 1: /* balances_force_unreserve_V7 - amount */;
                    return _toStringBalance(&m->basic.balances_force_unreserve_V7.amount, outValue, outValueLen, pageIdx,
                                            pageCount);
                default:
                    return parser_no_data;
            }
        case 1798: /* module 7 call 6 */
            switch (itemIdx) {
                case 0: /* balances_upgrade_accounts_V7 - who */;
                    return _toStringVecAccountId(&m->basic.balances_upgrade_accounts_V7.who, outValue, outValueLen, pageIdx,
                                                 pageCount);
                default:
                    return parser_no_data;
            }
        case 1800: /* module 7 call 8 */
            switch (itemIdx) {
                case 0: /* balances_force_set_balance_V7 - who */;
                    return _toStringAccountIdLookupOfT(&m->basic.balances_force_set_balance_V7.who, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 1: /* balances_force_set_balance_V7 - new_free */;
                    return _toStringCompactBalance(&m->basic.balances_force_set_balance_V7.new_free, outValue, outValueLen,
                                                   pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1801: /* module 7 call 9 */
            switch (itemIdx) {
                case 0: /* balances_force_adjust_total_issuance_V7 - direction */;
                    return _toStringAdjustmentDirection(&m->basic.balances_force_adjust_total_issuance_V7.direction,
                                                        outValue, outValueLen, pageIdx, pageCount);
                case 1: /* balances_force_adjust_total_issuance_V7 - delta */;
                    return _toStringCompactBalance(&m->basic.balances_force_adjust_total_issuance_V7.delta, outValue,
                                                   outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2825: /* module 11 call 9 */
            switch (itemIdx) {
                case 0: /* staking_set_validator_count_V7 - new_ */;
                    return _toStringCompactu32(&m->basic.staking_set_validator_count_V7.new_, outValue, outValueLen, pageIdx,
                                               pageCount);
                default:
                    return parser_no_data;
            }
        case 2826: /* module 11 call 10 */
            switch (itemIdx) {
                case 0: /* staking_increase_validator_count_V7 - additional */;
                    return _toStringCompactu32(&m->basic.staking_increase_validator_count_V7.additional, outValue,
                                               outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2827: /* module 11 call 11 */
            switch (itemIdx) {
                case 0: /* staking_scale_validator_count_V7 - factor */;
                    return _toStringPercent(&m->basic.staking_scale_validator_count_V7.factor, outValue, outValueLen,
                                            pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2828: /* module 11 call 12 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 2829: /* module 11 call 13 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 2830: /* module 11 call 14 */
            switch (itemIdx) {
                case 0: /* staking_set_invulnerables_V7 - invulnerables */;
                    return _toStringVecAccountId(&m->basic.staking_set_invulnerables_V7.invulnerables, outValue, outValueLen,
                                                 pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2831: /* module 11 call 15 */
            switch (itemIdx) {
                case 0: /* staking_force_unstake_V7 - stash */;
                    return _toStringAccountId(&m->basic.staking_force_unstake_V7.stash, outValue, outValueLen, pageIdx,
                                              pageCount);
                case 1: /* staking_force_unstake_V7 - num_slashing_spans */;
                    return _toStringu32(&m->basic.staking_force_unstake_V7.num_slashing_spans, outValue, outValueLen,
                                        pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2832: /* module 11 call 16 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 2833: /* module 11 call 17 */
            switch (itemIdx) {
                case 0: /* staking_cancel_deferred_slash_V7 - era */;
                    return _toStringEraIndex(&m->basic.staking_cancel_deferred_slash_V7.era, outValue, outValueLen, pageIdx,
                                             pageCount);
                case 1: /* staking_cancel_deferred_slash_V7 - slash_indices */;
                    return _toStringVecu32(&m->basic.staking_cancel_deferred_slash_V7.slash_indices, outValue, outValueLen,
                                           pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2836: /* module 11 call 20 */
            switch (itemIdx) {
                case 0: /* staking_reap_stash_V7 - stash */;
                    return _toStringAccountId(&m->basic.staking_reap_stash_V7.stash, outValue, outValueLen, pageIdx,
                                              pageCount);
                case 1: /* staking_reap_stash_V7 - num_slashing_spans */;
                    return _toStringu32(&m->basic.staking_reap_stash_V7.num_slashing_spans, outValue, outValueLen, pageIdx,
                                        pageCount);
                default:
                    return parser_no_data;
            }
        case 2837: /* module 11 call 21 */
            switch (itemIdx) {
                case 0: /* staking_kick_V7 - who */;
                    return _toStringVecAccountIdLookupOfT(&m->basic.staking_kick_V7.who, outValue, outValueLen, pageIdx,
                                                          pageCount);
                default:
                    return parser_no_data;
            }
        case 2838: /* module 11 call 22 */
            switch (itemIdx) {
                case 0: /* staking_set_staking_configs_V7 - min_nominator_bond */;
                    return _toStringConfigOpBalanceOfT(&m->basic.staking_set_staking_configs_V7.min_nominator_bond, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 1: /* staking_set_staking_configs_V7 - min_validator_bond */;
                    return _toStringConfigOpBalanceOfT(&m->basic.staking_set_staking_configs_V7.min_validator_bond, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 2: /* staking_set_staking_configs_V7 - max_nominator_count */;
                    return _toStringConfigOpu32(&m->basic.staking_set_staking_configs_V7.max_nominator_count, outValue,
                                                outValueLen, pageIdx, pageCount);
                case 3: /* staking_set_staking_configs_V7 - max_validator_count */;
                    return _toStringConfigOpu32(&m->basic.staking_set_staking_configs_V7.max_validator_count, outValue,
                                                outValueLen, pageIdx, pageCount);
                case 4: /* staking_set_staking_configs_V7 - chill_threshold */;
                    return _toStringConfigOpPercent(&m->basic.staking_set_staking_configs_V7.chill_threshold, outValue,
                                                    outValueLen, pageIdx, pageCount);
                case 5: /* staking_set_staking_configs_V7 - min_commission */;
                    return _toStringConfigOpPerbill(&m->basic.staking_set_staking_configs_V7.min_commission, outValue,
                                                    outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2839: /* module 11 call 23 */
            switch (itemIdx) {
                case 0: /* staking_chill_other_V7 - stash */;
                    return _toStringAccountId(&m->basic.staking_chill_other_V7.stash, outValue, outValueLen, pageIdx,
                                              pageCount);
                default:
                    return parser_no_data;
            }
        case 2840: /* module 11 call 24 */
            switch (itemIdx) {
                case 0: /* staking_force_apply_min_commission_V7 - validator_stash */;
                    return _toStringAccountId(&m->basic.staking_force_apply_min_commission_V7.validator_stash, outValue,
                                              outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 2841: /* module 11 call 25 */
            switch (itemIdx) {
                case 0: /* staking_set_min_commission_V7 - new_ */;
                    return _toStringPerbill(&m->basic.staking_set_min_commission_V7.new_, outValue, outValueLen, pageIdx,
                                            pageCount);
                default:
                    return parser_no_data;
            }
        case 2842: /* module 11 call 26 */
            switch (itemIdx) {
                case 0: /* staking_payout_stakers_by_page_V7 - validator_stash */;
                    return _toStringAccountId(&m->basic.staking_payout_stakers_by_page_V7.validator_stash, outValue,
                                              outValueLen, pageIdx, pageCount);
                case 1: /* staking_payout_stakers_by_page_V7 - era */;
                    return _toStringEraIndex(&m->basic.staking_payout_stakers_by_page_V7.era, outValue, outValueLen, pageIdx,
                                             pageCount);
                case 2: /* staking_payout_stakers_by_page_V7 - page */;
                    return _toStringPage(&m->basic.staking_payout_stakers_by_page_V7.page, outValue, outValueLen, pageIdx,
                                         pageCount);
                default:
                    return parser_no_data;
            }
        case 2843: /* module 11 call 27 */
            switch (itemIdx) {
                case 0: /* staking_update_payee_V7 - controller */;
                    return _toStringAccountId(&m->basic.staking_update_payee_V7.controller, outValue, outValueLen, pageIdx,
                                              pageCount);
                default:
                    return parser_no_data;
            }
        case 2845: /* module 11 call 29 */
            switch (itemIdx) {
                case 0: /* staking_restore_ledger_V7 - stash */;
                    return _toStringAccountId(&m->basic.staking_restore_ledger_V7.stash, outValue, outValueLen, pageIdx,
                                              pageCount);
                case 1: /* staking_restore_ledger_V7 - maybe_controller */;
                    return _toStringOptionAccountId(&m->basic.staking_restore_ledger_V7.maybe_controller, outValue,
                                                    outValueLen, pageIdx, pageCount);
                case 2: /* staking_restore_ledger_V7 - maybe_total */;
                    return _toStringOptionBalance(&m->basic.staking_restore_ledger_V7.maybe_total, outValue, outValueLen,
                                                  pageIdx, pageCount);
                case 3: /* staking_restore_ledger_V7 - maybe_unlocking */;
                    return _toStringOptionBoundedVecUnlockChunkBalanceOfTMaxUnlockingChunks(&m->basic
                                                                                                 .staking_restore_ledger_V7
                                                                                                 .maybe_unlocking,
                                                                                            outValue, outValueLen, pageIdx,
                                                                                            pageCount);
                default:
                    return parser_no_data;
            }
        case 3072: /* module 12 call 0 */
            switch (itemIdx) {
                case 0: /* stakingextension_change_endpoint_V7 - endpoint */;
                    return _toStringVecu8(&m->basic.stakingextension_change_endpoint_V7.endpoint, outValue, outValueLen,
                                          pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 3073: /* module 12 call 1 */
            switch (itemIdx) {
                case 0: /* stakingextension_change_threshold_accounts_V7 - tss_account */;
                    return _toStringAccountId(&m->basic.stakingextension_change_threshold_accounts_V7.tss_account, outValue,
                                              outValueLen, pageIdx, pageCount);
                case 1: /* stakingextension_change_threshold_accounts_V7 - x25519_public_key */;
                    return _toStringX25519PublicKey(&m->basic.stakingextension_change_threshold_accounts_V7
                                                         .x25519_public_key,
                                                    outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 3074: /* module 12 call 2 */
            switch (itemIdx) {
                case 0: /* stakingextension_withdraw_unbonded_V7 - num_slashing_spans */;
                    return _toStringu32(&m->basic.stakingextension_withdraw_unbonded_V7.num_slashing_spans, outValue,
                                        outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 3075: /* module 12 call 3 */
            switch (itemIdx) {
                case 0: /* stakingextension_validate_V7 - prefs */;
                    return _toStringValidatorPrefs(&m->basic.stakingextension_validate_V7.prefs, outValue, outValueLen,
                                                   pageIdx, pageCount);
                case 1: /* stakingextension_validate_V7 - server_info */;
                    return _toStringServerInfoAccountId(&m->basic.stakingextension_validate_V7.server_info, outValue,
                                                        outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 3076: /* module 12 call 4 */
            switch (itemIdx) {
                case 0: /* stakingextension_declare_synced_V7 - synced */;
                    return _toStringbool(&m->basic.stakingextension_declare_synced_V7.synced, outValue, outValueLen, pageIdx,
                                         pageCount);
                default:
                    return parser_no_data;
            }
        case 11264: /* module 44 call 0 */
            switch (itemIdx) {
                case 0: /* proxy_proxy_V7 - real */;
                    return _toStringAccountIdLookupOfT(&m->nested.proxy_proxy_V7.real, outValue, outValueLen, pageIdx,
                                                       pageCount);
                case 1: /* proxy_proxy_V7 - force_proxy_type */;
                    return _toStringOptionProxyType(&m->nested.proxy_proxy_V7.force_proxy_type, outValue, outValueLen,
                                                    pageIdx, pageCount);
                case 2: /* proxy_proxy_V7 - call */;
                    return _toStringCall(&m->nested.proxy_proxy_V7.call, outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 11265: /* module 44 call 1 */
            switch (itemIdx) {
                case 0: /* proxy_add_proxy_V7 - delegate */;
                    return _toStringAccountIdLookupOfT(&m->nested.proxy_add_proxy_V7.delegate, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 1: /* proxy_add_proxy_V7 - proxy_type */;
                    return _toStringProxyType(&m->nested.proxy_add_proxy_V7.proxy_type, outValue, outValueLen, pageIdx,
                                              pageCount);
                case 2: /* proxy_add_proxy_V7 - delay */;
                    return _toStringBlockNumber(&m->nested.proxy_add_proxy_V7.delay, outValue, outValueLen, pageIdx,
                                                pageCount);
                default:
                    return parser_no_data;
            }
        case 11266: /* module 44 call 2 */
            switch (itemIdx) {
                case 0: /* proxy_remove_proxy_V7 - delegate */;
                    return _toStringAccountIdLookupOfT(&m->nested.proxy_remove_proxy_V7.delegate, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 1: /* proxy_remove_proxy_V7 - proxy_type */;
                    return _toStringProxyType(&m->nested.proxy_remove_proxy_V7.proxy_type, outValue, outValueLen, pageIdx,
                                              pageCount);
                case 2: /* proxy_remove_proxy_V7 - delay */;
                    return _toStringBlockNumber(&m->nested.proxy_remove_proxy_V7.delay, outValue, outValueLen, pageIdx,
                                                pageCount);
                default:
                    return parser_no_data;
            }
        case 11267: /* module 44 call 3 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 11268: /* module 44 call 4 */
            switch (itemIdx) {
                case 0: /* proxy_create_pure_V7 - proxy_type */;
                    return _toStringProxyType(&m->nested.proxy_create_pure_V7.proxy_type, outValue, outValueLen, pageIdx,
                                              pageCount);
                case 1: /* proxy_create_pure_V7 - delay */;
                    return _toStringBlockNumber(&m->nested.proxy_create_pure_V7.delay, outValue, outValueLen, pageIdx,
                                                pageCount);
                case 2: /* proxy_create_pure_V7 - index */;
                    return _toStringu16(&m->nested.proxy_create_pure_V7.index, outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 11269: /* module 44 call 5 */
            switch (itemIdx) {
                case 0: /* proxy_kill_pure_V7 - spawner */;
                    return _toStringAccountIdLookupOfT(&m->nested.proxy_kill_pure_V7.spawner, outValue, outValueLen, pageIdx,
                                                       pageCount);
                case 1: /* proxy_kill_pure_V7 - proxy_type */;
                    return _toStringProxyType(&m->nested.proxy_kill_pure_V7.proxy_type, outValue, outValueLen, pageIdx,
                                              pageCount);
                case 2: /* proxy_kill_pure_V7 - index */;
                    return _toStringu16(&m->nested.proxy_kill_pure_V7.index, outValue, outValueLen, pageIdx, pageCount);
                case 3: /* proxy_kill_pure_V7 - height */;
                    return _toStringCompactu32(&m->nested.proxy_kill_pure_V7.height, outValue, outValueLen, pageIdx,
                                               pageCount);
                case 4: /* proxy_kill_pure_V7 - ext_index */;
                    return _toStringCompactu32(&m->nested.proxy_kill_pure_V7.ext_index, outValue, outValueLen, pageIdx,
                                               pageCount);
                default:
                    return parser_no_data;
            }
        case 11270: /* module 44 call 6 */
            switch (itemIdx) {
                case 0: /* proxy_announce_V7 - real */;
                    return _toStringAccountIdLookupOfT(&m->basic.proxy_announce_V7.real, outValue, outValueLen, pageIdx,
                                                       pageCount);
                case 1: /* proxy_announce_V7 - call_hash */;
                    return _toStringCallHashOf(&m->basic.proxy_announce_V7.call_hash, outValue, outValueLen, pageIdx,
                                               pageCount);
                default:
                    return parser_no_data;
            }
        case 11271: /* module 44 call 7 */
            switch (itemIdx) {
                case 0: /* proxy_remove_announcement_V7 - real */;
                    return _toStringAccountIdLookupOfT(&m->basic.proxy_remove_announcement_V7.real, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 1: /* proxy_remove_announcement_V7 - call_hash */;
                    return _toStringCallHashOf(&m->basic.proxy_remove_announcement_V7.call_hash, outValue, outValueLen,
                                               pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 11272: /* module 44 call 8 */
            switch (itemIdx) {
                case 0: /* proxy_reject_announcement_V7 - delegate */;
                    return _toStringAccountIdLookupOfT(&m->basic.proxy_reject_announcement_V7.delegate, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 1: /* proxy_reject_announcement_V7 - call_hash */;
                    return _toStringCallHashOf(&m->basic.proxy_reject_announcement_V7.call_hash, outValue, outValueLen,
                                               pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 11273: /* module 44 call 9 */
            switch (itemIdx) {
                case 0: /* proxy_proxy_announced_V7 - delegate */;
                    return _toStringAccountIdLookupOfT(&m->basic.proxy_proxy_announced_V7.delegate, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 1: /* proxy_proxy_announced_V7 - real */;
                    return _toStringAccountIdLookupOfT(&m->basic.proxy_proxy_announced_V7.real, outValue, outValueLen,
                                                       pageIdx, pageCount);
                case 2: /* proxy_proxy_announced_V7 - force_proxy_type */;
                    return _toStringOptionProxyType(&m->basic.proxy_proxy_announced_V7.force_proxy_type, outValue,
                                                    outValueLen, pageIdx, pageCount);
                case 3: /* proxy_proxy_announced_V7 - call */;
                    return _toStringCall(&m->basic.proxy_proxy_announced_V7.call, outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 13056: /* module 51 call 0 */
            switch (itemIdx) {
                case 0: /* registry_register_V7 - program_modification_account */;
                    return _toStringAccountId(&m->basic.registry_register_V7.program_modification_account, outValue,
                                              outValueLen, pageIdx, pageCount);
                case 1: /* registry_register_V7 - key_visibility */;
                    return _toStringKeyVisibility(&m->basic.registry_register_V7.key_visibility, outValue, outValueLen,
                                                  pageIdx, pageCount);
                case 2: /* registry_register_V7 - programs_data */;
                    return _toStringBoundedVecProgramInstanceTMaxProgramHashes(&m->basic.registry_register_V7.programs_data,
                                                                               outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 13057: /* module 51 call 1 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 13058: /* module 51 call 2 */
            switch (itemIdx) {
                case 0: /* registry_change_program_instance_V7 - verifying_key */;
                    return _toStringVerifyingKey(&m->basic.registry_change_program_instance_V7.verifying_key, outValue,
                                                 outValueLen, pageIdx, pageCount);
                case 1: /* registry_change_program_instance_V7 - new_program_instance */;
                    return _toStringBoundedVecProgramInstanceTMaxProgramHashes(&m->basic.registry_change_program_instance_V7
                                                                                    .new_program_instance,
                                                                               outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 13059: /* module 51 call 3 */
            switch (itemIdx) {
                case 0: /* registry_change_program_modification_account_V7 - verifying_key */;
                    return _toStringVerifyingKey(&m->basic.registry_change_program_modification_account_V7.verifying_key,
                                                 outValue, outValueLen, pageIdx, pageCount);
                case 1: /* registry_change_program_modification_account_V7 - new_program_mod_account */;
                    return _toStringAccountId(&m->basic.registry_change_program_modification_account_V7
                                                   .new_program_mod_account,
                                              outValue, outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 13060: /* module 51 call 4 */
            switch (itemIdx) {
                case 0: /* registry_confirm_register_V7 - sig_req_account */;
                    return _toStringAccountId(&m->basic.registry_confirm_register_V7.sig_req_account, outValue, outValueLen,
                                              pageIdx, pageCount);
                case 1: /* registry_confirm_register_V7 - signing_subgroup */;
                    return _toStringu8(&m->basic.registry_confirm_register_V7.signing_subgroup, outValue, outValueLen,
                                       pageIdx, pageCount);
                case 2: /* registry_confirm_register_V7 - verifying_key */;
                    return _toStringBoundedVecu8(&m->basic.registry_confirm_register_V7.verifying_key, outValue, outValueLen,
                                                 pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 13568: /* module 53 call 0 */
            switch (itemIdx) {
                case 0: /* programs_set_program_V7 - new_program */;
                    return _toStringVecu8(&m->basic.programs_set_program_V7.new_program, outValue, outValueLen, pageIdx,
                                          pageCount);
                case 1: /* programs_set_program_V7 - configuration_schema */;
                    return _toStringVecu8(&m->basic.programs_set_program_V7.configuration_schema, outValue, outValueLen,
                                          pageIdx, pageCount);
                case 2: /* programs_set_program_V7 - auxiliary_data_schema */;
                    return _toStringVecu8(&m->basic.programs_set_program_V7.auxiliary_data_schema, outValue, outValueLen,
                                          pageIdx, pageCount);
                case 3: /* programs_set_program_V7 - oracle_data_pointer */;
                    return _toStringVecu8(&m->basic.programs_set_program_V7.oracle_data_pointer, outValue, outValueLen,
                                          pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 13569: /* module 53 call 1 */
            switch (itemIdx) {
                case 0: /* programs_remove_program_V7 - program_hash */;
                    return _toStringHash(&m->basic.programs_remove_program_V7.program_hash, outValue, outValueLen, pageIdx,
                                         pageCount);
                default:
                    return parser_no_data;
            }
#endif
        default:
            return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V7(uint8_t moduleIdx, uint8_t callIdx, __Z_UNUSED uint8_t itemIdx) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 2819:  // Staking:Withdraw Unbonded
            switch (itemIdx) {
                case 0:  // Num slashing spans
                    return true;
                default:
                    return false;
            }
        case 2831:  // Staking:Force unstake
            switch (itemIdx) {
                case 1:  // Num slashing spans
                    return true;
                default:
                    return false;
            }
        case 2836:  // Staking:Reap stash
            switch (itemIdx) {
                case 1:  // Num slashing spans
                    return true;
                default:
                    return false;
            }
        case 3074:  // StakingExtension:Withdraw Unbonded
            switch (itemIdx) {
                case 0:  // Num slashing spans
                    return true;
                default:
                    return false;
            }

        default:
            return false;
    }
}

bool _getMethod_IsNestingSupported_V7(uint8_t moduleIdx, uint8_t callIdx) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 265:    // System:Authorize upgrade
        case 266:    // System:Authorize upgrade without checks
        case 267:    // System:Apply authorized upgrade
        case 512:    // Utility:Batch
        case 514:    // Utility:Batch all
        case 515:    // Utility:Dispatch as
        case 516:    // Utility:Force batch
        case 517:    // Utility:With weight
        case 1797:   // Balances:Force unreserve
        case 1798:   // Balances:Upgrade accounts
        case 1800:   // Balances:Force set balance
        case 1801:   // Balances:Force adjust total issuance
        case 2825:   // Staking:Set validator count
        case 2826:   // Staking:Increase validator count
        case 2827:   // Staking:Scale validator count
        case 2828:   // Staking:Force no eras
        case 2829:   // Staking:Force new era
        case 2830:   // Staking:Set invulnerables
        case 2831:   // Staking:Force unstake
        case 2832:   // Staking:Force new era always
        case 2833:   // Staking:Cancel deferred slash
        case 2836:   // Staking:Reap stash
        case 2837:   // Staking:Kick
        case 2838:   // Staking:Set staking configs
        case 2839:   // Staking:Chill other
        case 2840:   // Staking:Force apply min commission
        case 2841:   // Staking:Set min commission
        case 2842:   // Staking:Payout stakers by page
        case 2843:   // Staking:Update payee
        case 2845:   // Staking:Restore ledger
        case 3072:   // StakingExtension:Change endpoint
        case 3073:   // StakingExtension:Change threshold accounts
        case 3074:   // StakingExtension:Withdraw Unbonded
        case 3075:   // StakingExtension:Validate
        case 3076:   // StakingExtension:Declare synced
        case 11267:  // Proxy:Remove proxies
        case 11270:  // Proxy:Announce
        case 11271:  // Proxy:Remove announcement
        case 11272:  // Proxy:Reject announcement
        case 11273:  // Proxy:Proxy announced
        case 13056:  // Registry:Register
        case 13057:  // Registry:Prune registration
        case 13058:  // Registry:Change program instance
        case 13059:  // Registry:Change program modification account
        case 13060:  // Registry:Confirm register
        case 13568:  // Programs:Set program
        case 13569:  // Programs:Remove program
            return false;
        default:
            return true;
    }
}
