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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"

extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#include "substrate_types.h"
#include "substrate_types_V7.h"
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_SYSTEM_V7 1
#define PD_CALL_UTILITY_V7 2
#define PD_CALL_BALANCES_V7 7
#define PD_CALL_STAKING_V7 11
#define PD_CALL_STAKINGEXTENSION_V7 12
#define PD_CALL_SESSION_V7 20
#define PD_CALL_PROXY_V7 44
#define PD_CALL_REGISTRY_V7 51
#define PD_CALL_PROGRAMS_V7 53

#define PD_CALL_UTILITY_BATCH_V7 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V7_t;

#define PD_CALL_UTILITY_BATCH_ALL_V7 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V7_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V7 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V7_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif

#define PD_CALL_SYSTEM_AUTHORIZE_UPGRADE_V7 9
typedef struct {
    pd_Hash_t code_hash;
} pd_system_authorize_upgrade_V7_t;

#define PD_CALL_SYSTEM_AUTHORIZE_UPGRADE_WITHOUT_CHECKS_V7 10
typedef struct {
    pd_Hash_t code_hash;
} pd_system_authorize_upgrade_without_checks_V7_t;

#define PD_CALL_SYSTEM_APPLY_AUTHORIZED_UPGRADE_V7 11
typedef struct {
    pd_Vecu8_t code;
} pd_system_apply_authorized_upgrade_V7_t;

#define PD_CALL_UTILITY_DISPATCH_AS_V7 3
typedef struct {
    pd_BoxPalletsOrigin_t as_origin;
    pd_Call_t call;
} pd_utility_dispatch_as_V7_t;

#define PD_CALL_UTILITY_WITH_WEIGHT_V7 5
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_utility_with_weight_V7_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V7 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V7_t;

#define PD_CALL_BALANCES_UPGRADE_ACCOUNTS_V7 6
typedef struct {
    pd_VecAccountId_t who;
} pd_balances_upgrade_accounts_V7_t;

#define PD_CALL_BALANCES_FORCE_SET_BALANCE_V7 8
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
} pd_balances_force_set_balance_V7_t;

#define PD_CALL_BALANCES_FORCE_ADJUST_TOTAL_ISSUANCE_V7 9
typedef struct {
    pd_AdjustmentDirection_t direction;
    pd_CompactBalance_t delta;
} pd_balances_force_adjust_total_issuance_V7_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V7 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V7_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V7 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V7_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V7 11
typedef struct {
    pd_Percent_t factor;
} pd_staking_scale_validator_count_V7_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V7 12
typedef struct {
} pd_staking_force_no_eras_V7_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V7 13
typedef struct {
} pd_staking_force_new_era_V7_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V7 14
typedef struct {
    pd_VecAccountId_t invulnerables;
} pd_staking_set_invulnerables_V7_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V7 15
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V7_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V7 16
typedef struct {
} pd_staking_force_new_era_always_V7_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V7 17
typedef struct {
    pd_EraIndex_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V7_t;

#define PD_CALL_STAKING_REAP_STASH_V7 20
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V7_t;

#define PD_CALL_STAKING_KICK_V7 21
typedef struct {
    pd_VecAccountIdLookupOfT_t who;
} pd_staking_kick_V7_t;

#define PD_CALL_STAKING_SET_STAKING_CONFIGS_V7 22
typedef struct {
    pd_ConfigOpBalanceOfT_t min_nominator_bond;
    pd_ConfigOpBalanceOfT_t min_validator_bond;
    pd_ConfigOpu32_t max_nominator_count;
    pd_ConfigOpu32_t max_validator_count;
    pd_ConfigOpPercent_t chill_threshold;
    pd_ConfigOpPerbill_t min_commission;
} pd_staking_set_staking_configs_V7_t;

#define PD_CALL_STAKING_CHILL_OTHER_V7 23
typedef struct {
    pd_AccountId_t stash;
} pd_staking_chill_other_V7_t;

#define PD_CALL_STAKING_FORCE_APPLY_MIN_COMMISSION_V7 24
typedef struct {
    pd_AccountId_t validator_stash;
} pd_staking_force_apply_min_commission_V7_t;

#define PD_CALL_STAKING_SET_MIN_COMMISSION_V7 25
typedef struct {
    pd_Perbill_t new_;
} pd_staking_set_min_commission_V7_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_BY_PAGE_V7 26
typedef struct {
    pd_AccountId_t validator_stash;
    pd_EraIndex_t era;
    pd_Page_t page;
} pd_staking_payout_stakers_by_page_V7_t;

#define PD_CALL_STAKING_UPDATE_PAYEE_V7 27
typedef struct {
    pd_AccountId_t controller;
} pd_staking_update_payee_V7_t;

#define PD_CALL_STAKINGEXTENSION_CHANGE_ENDPOINT_V7 0
typedef struct {
    pd_Vecu8_t endpoint;
} pd_stakingextension_change_endpoint_V7_t;

#define PD_CALL_STAKINGEXTENSION_CHANGE_THRESHOLD_ACCOUNTS_V7 1
typedef struct {
    pd_AccountId_t tss_account;
    pd_X25519PublicKey_t x25519_public_key;
} pd_stakingextension_change_threshold_accounts_V7_t;

#define PD_CALL_STAKINGEXTENSION_WITHDRAW_UNBONDED_V7 2
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_stakingextension_withdraw_unbonded_V7_t;

#define PD_CALL_STAKINGEXTENSION_VALIDATE_V7 3
typedef struct {
    pd_ValidatorPrefs_t prefs;
    pd_ServerInfoAccountId_t server_info;
} pd_stakingextension_validate_V7_t;

#define PD_CALL_STAKINGEXTENSION_DECLARE_SYNCED_V7 4
typedef struct {
    pd_bool_t synced;
} pd_stakingextension_declare_synced_V7_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V7 3
typedef struct {
} pd_proxy_remove_proxies_V7_t;

#define PD_CALL_PROXY_ANNOUNCE_V7 6
typedef struct {
    pd_AccountIdLookupOfT_t real;
    pd_CallHashOf_t call_hash;
} pd_proxy_announce_V7_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V7 7
typedef struct {
    pd_AccountIdLookupOfT_t real;
    pd_CallHashOf_t call_hash;
} pd_proxy_remove_announcement_V7_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V7 8
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_CallHashOf_t call_hash;
} pd_proxy_reject_announcement_V7_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V7 9
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_AccountIdLookupOfT_t real;
    pd_OptionProxyType_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V7_t;

#define PD_CALL_REGISTRY_REGISTER_V7 0
typedef struct {
    pd_AccountId_t program_modification_account;
    pd_KeyVisibility_t key_visibility;
    pd_BoundedVecProgramInstanceTMaxProgramHashes_t programs_data;
} pd_registry_register_V7_t;

#define PD_CALL_REGISTRY_PRUNE_REGISTRATION_V7 1
typedef struct {
} pd_registry_prune_registration_V7_t;

#define PD_CALL_REGISTRY_CHANGE_PROGRAM_INSTANCE_V7 2
typedef struct {
    pd_VerifyingKey_t verifying_key;
    pd_BoundedVecProgramInstanceTMaxProgramHashes_t new_program_instance;
} pd_registry_change_program_instance_V7_t;

#define PD_CALL_REGISTRY_CHANGE_PROGRAM_MODIFICATION_ACCOUNT_V7 3
typedef struct {
    pd_VerifyingKey_t verifying_key;
    pd_AccountId_t new_program_mod_account;
} pd_registry_change_program_modification_account_V7_t;

#define PD_CALL_REGISTRY_CONFIRM_REGISTER_V7 4
typedef struct {
    pd_AccountId_t sig_req_account;
    pd_u8_t signing_subgroup;
    pd_BoundedVecu8_t verifying_key;
} pd_registry_confirm_register_V7_t;

#define PD_CALL_PROGRAMS_SET_PROGRAM_V7 0
typedef struct {
    pd_Vecu8_t new_program;
    pd_Vecu8_t configuration_schema;
    pd_Vecu8_t auxiliary_data_schema;
    pd_Vecu8_t oracle_data_pointer;
} pd_programs_set_program_V7_t;

#define PD_CALL_PROGRAMS_REMOVE_PROGRAM_V7 1
typedef struct {
    pd_Hash_t program_hash;
} pd_programs_remove_program_V7_t;

#endif

typedef union {
    pd_utility_batch_V7_t utility_batch_V7;
    pd_utility_batch_all_V7_t utility_batch_all_V7;
    pd_utility_force_batch_V7_t utility_force_batch_V7;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_system_authorize_upgrade_V7_t system_authorize_upgrade_V7;
    pd_system_authorize_upgrade_without_checks_V7_t system_authorize_upgrade_without_checks_V7;
    pd_system_apply_authorized_upgrade_V7_t system_apply_authorized_upgrade_V7;
    pd_utility_dispatch_as_V7_t utility_dispatch_as_V7;
    pd_utility_with_weight_V7_t utility_with_weight_V7;
    pd_balances_force_unreserve_V7_t balances_force_unreserve_V7;
    pd_balances_upgrade_accounts_V7_t balances_upgrade_accounts_V7;
    pd_balances_force_set_balance_V7_t balances_force_set_balance_V7;
    pd_balances_force_adjust_total_issuance_V7_t balances_force_adjust_total_issuance_V7;
    pd_staking_set_validator_count_V7_t staking_set_validator_count_V7;
    pd_staking_increase_validator_count_V7_t staking_increase_validator_count_V7;
    pd_staking_scale_validator_count_V7_t staking_scale_validator_count_V7;
    pd_staking_force_no_eras_V7_t staking_force_no_eras_V7;
    pd_staking_force_new_era_V7_t staking_force_new_era_V7;
    pd_staking_set_invulnerables_V7_t staking_set_invulnerables_V7;
    pd_staking_force_unstake_V7_t staking_force_unstake_V7;
    pd_staking_force_new_era_always_V7_t staking_force_new_era_always_V7;
    pd_staking_cancel_deferred_slash_V7_t staking_cancel_deferred_slash_V7;
    pd_staking_reap_stash_V7_t staking_reap_stash_V7;
    pd_staking_kick_V7_t staking_kick_V7;
    pd_staking_set_staking_configs_V7_t staking_set_staking_configs_V7;
    pd_staking_chill_other_V7_t staking_chill_other_V7;
    pd_staking_force_apply_min_commission_V7_t staking_force_apply_min_commission_V7;
    pd_staking_set_min_commission_V7_t staking_set_min_commission_V7;
    pd_staking_payout_stakers_by_page_V7_t staking_payout_stakers_by_page_V7;
    pd_staking_update_payee_V7_t staking_update_payee_V7;
    pd_stakingextension_change_endpoint_V7_t stakingextension_change_endpoint_V7;
    pd_stakingextension_change_threshold_accounts_V7_t stakingextension_change_threshold_accounts_V7;
    pd_stakingextension_withdraw_unbonded_V7_t stakingextension_withdraw_unbonded_V7;
    pd_stakingextension_validate_V7_t stakingextension_validate_V7;
    pd_stakingextension_declare_synced_V7_t stakingextension_declare_synced_V7;
    pd_proxy_remove_proxies_V7_t proxy_remove_proxies_V7;
    pd_proxy_announce_V7_t proxy_announce_V7;
    pd_proxy_remove_announcement_V7_t proxy_remove_announcement_V7;
    pd_proxy_reject_announcement_V7_t proxy_reject_announcement_V7;
    pd_proxy_proxy_announced_V7_t proxy_proxy_announced_V7;
    pd_registry_register_V7_t registry_register_V7;
    pd_registry_prune_registration_V7_t registry_prune_registration_V7;
    pd_registry_change_program_instance_V7_t registry_change_program_instance_V7;
    pd_registry_change_program_modification_account_V7_t registry_change_program_modification_account_V7;
    pd_registry_confirm_register_V7_t registry_confirm_register_V7;
    pd_programs_set_program_V7_t programs_set_program_V7;
    pd_programs_remove_program_V7_t programs_remove_program_V7;
#endif
} pd_MethodBasic_V7_t;

#define PD_CALL_BALANCES_TRANSFER_ALLOW_DEATH_V7 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_allow_death_V7_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V7 2
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V7_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V7 3
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V7_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V7 4
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V7_t;

#define PD_CALL_STAKING_BOND_V7 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_RewardDestination_t payee;
} pd_staking_bond_V7_t;

#define PD_CALL_STAKING_BOND_EXTRA_V7 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V7_t;

#define PD_CALL_STAKING_UNBOND_V7 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V7_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V7 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V7_t;

#define PD_CALL_STAKING_VALIDATE_V7 4
typedef struct {
    pd_ValidatorPrefs_t prefs;
} pd_staking_validate_V7_t;

#define PD_CALL_STAKING_NOMINATE_V7 5
typedef struct {
    pd_VecAccountIdLookupOfT_t targets;
} pd_staking_nominate_V7_t;

#define PD_CALL_STAKING_CHILL_V7 6
typedef struct {
} pd_staking_chill_V7_t;

#define PD_CALL_STAKING_SET_PAYEE_V7 7
typedef struct {
    pd_RewardDestination_t payee;
} pd_staking_set_payee_V7_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V7 8
typedef struct {
} pd_staking_set_controller_V7_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V7 18
typedef struct {
    pd_AccountId_t validator_stash;
    pd_EraIndex_t era;
} pd_staking_payout_stakers_V7_t;

#define PD_CALL_STAKING_REBOND_V7 19
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V7_t;

#define PD_CALL_SESSION_SET_KEYS_V7 0
typedef struct {
    pd_Keys_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V7_t;

#define PD_CALL_SESSION_PURGE_KEYS_V7 1
typedef struct {
} pd_session_purge_keys_V7_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#define PD_CALL_SYSTEM_REMARK_V7 0
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_V7_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V7 1
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V7_t;

#define PD_CALL_SYSTEM_SET_CODE_V7 2
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_V7_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V7 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V7_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V7 7
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V7_t;

#define PD_CALL_PROXY_PROXY_V7 0
typedef struct {
    pd_AccountIdLookupOfT_t real;
    pd_OptionProxyType_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V7_t;

#define PD_CALL_PROXY_ADD_PROXY_V7 1
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V7_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V7 2
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V7_t;

#define PD_CALL_PROXY_CREATE_PURE_V7 4
typedef struct {
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_create_pure_V7_t;

#define PD_CALL_PROXY_KILL_PURE_V7 5
typedef struct {
    pd_AccountIdLookupOfT_t spawner;
    pd_ProxyType_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_pure_V7_t;

#endif

typedef union {
    pd_balances_transfer_allow_death_V7_t balances_transfer_allow_death_V7;
    pd_balances_force_transfer_V7_t balances_force_transfer_V7;
    pd_balances_transfer_keep_alive_V7_t balances_transfer_keep_alive_V7;
    pd_balances_transfer_all_V7_t balances_transfer_all_V7;
    pd_staking_bond_V7_t staking_bond_V7;
    pd_staking_bond_extra_V7_t staking_bond_extra_V7;
    pd_staking_unbond_V7_t staking_unbond_V7;
    pd_staking_withdraw_unbonded_V7_t staking_withdraw_unbonded_V7;
    pd_staking_validate_V7_t staking_validate_V7;
    pd_staking_nominate_V7_t staking_nominate_V7;
    pd_staking_chill_V7_t staking_chill_V7;
    pd_staking_set_payee_V7_t staking_set_payee_V7;
    pd_staking_set_controller_V7_t staking_set_controller_V7;
    pd_staking_payout_stakers_V7_t staking_payout_stakers_V7;
    pd_staking_rebond_V7_t staking_rebond_V7;
    pd_session_set_keys_V7_t session_set_keys_V7;
    pd_session_purge_keys_V7_t session_purge_keys_V7;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_system_remark_V7_t system_remark_V7;
    pd_system_set_heap_pages_V7_t system_set_heap_pages_V7;
    pd_system_set_code_V7_t system_set_code_V7;
    pd_system_set_code_without_checks_V7_t system_set_code_without_checks_V7;
    pd_system_remark_with_event_V7_t system_remark_with_event_V7;
    pd_proxy_proxy_V7_t proxy_proxy_V7;
    pd_proxy_add_proxy_V7_t proxy_add_proxy_V7;
    pd_proxy_remove_proxy_V7_t proxy_remove_proxy_V7;
    pd_proxy_create_pure_V7_t proxy_create_pure_V7;
    pd_proxy_kill_pure_V7_t proxy_kill_pure_V7;
#endif
} pd_MethodNested_V7_t;

typedef union {
    pd_MethodBasic_V7_t basic;
    pd_MethodNested_V7_t nested;
} pd_Method_V7_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
