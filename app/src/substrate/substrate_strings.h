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

// Modules names
static const char *STR_MO_SYSTEM = "System";
static const char *STR_MO_UTILITY = "Utility";
static const char *STR_MO_BALANCES = "Balances";
static const char *STR_MO_STAKING = "Staking";
static const char *STR_MO_STAKINGEXTENSION = "Stakingextension";
static const char *STR_MO_SESSION = "Session";
static const char *STR_MO_PROXY = "Proxy";
static const char *STR_MO_REGISTRY = "Registry";
static const char *STR_MO_PROGRAMS = "Programs";

// Methods names
static const char *STR_ME_REMARK = "Remark";
static const char *STR_ME_SET_HEAP_PAGES = "Set heap pages";
static const char *STR_ME_SET_CODE = "Set code";
static const char *STR_ME_SET_CODE_WITHOUT_CHECKS = "Set code without checks";
static const char *STR_ME_REMARK_WITH_EVENT = "Remark with event";
static const char *STR_ME_AUTHORIZE_UPGRADE = "Authorize upgrade";
static const char *STR_ME_AUTHORIZE_UPGRADE_WITHOUT_CHECKS = "Authorize upgrade without checks";
static const char *STR_ME_APPLY_AUTHORIZED_UPGRADE = "Apply authorized upgrade";
static const char *STR_ME_BATCH = "Batch";
static const char *STR_ME_BATCH_ALL = "Batch all";
static const char *STR_ME_DISPATCH_AS = "Dispatch as";
static const char *STR_ME_FORCE_BATCH = "Force batch";
static const char *STR_ME_WITH_WEIGHT = "With weight";
static const char *STR_ME_TRANSFER_ALLOW_DEATH = "Transfer allow death";
static const char *STR_ME_FORCE_TRANSFER = "Force transfer";
static const char *STR_ME_TRANSFER_KEEP_ALIVE = "Transfer keep alive";
static const char *STR_ME_TRANSFER_ALL = "Transfer all";
static const char *STR_ME_FORCE_UNRESERVE = "Force unreserve";
static const char *STR_ME_UPGRADE_ACCOUNTS = "Upgrade accounts";
static const char *STR_ME_FORCE_SET_BALANCE = "Force set balance";
static const char *STR_ME_FORCE_ADJUST_TOTAL_ISSUANCE = "Force adjust total issuance";
static const char *STR_ME_BOND = "Bond";
static const char *STR_ME_BOND_EXTRA = "Bond extra";
static const char *STR_ME_UNBOND = "Unbond";
static const char *STR_ME_WITHDRAW_UNBONDED = "Withdraw Unbonded";
static const char *STR_ME_VALIDATE = "Validate";
static const char *STR_ME_NOMINATE = "Nominate";
static const char *STR_ME_CHILL = "Chill";
static const char *STR_ME_SET_PAYEE = "Set payee";
static const char *STR_ME_SET_CONTROLLER = "Set controller";
static const char *STR_ME_SET_VALIDATOR_COUNT = "Set validator count";
static const char *STR_ME_INCREASE_VALIDATOR_COUNT = "Increase validator count";
static const char *STR_ME_SCALE_VALIDATOR_COUNT = "Scale validator count";
static const char *STR_ME_FORCE_NO_ERAS = "Force no eras";
static const char *STR_ME_FORCE_NEW_ERA = "Force new era";
static const char *STR_ME_SET_INVULNERABLES = "Set invulnerables";
static const char *STR_ME_FORCE_UNSTAKE = "Force unstake";
static const char *STR_ME_FORCE_NEW_ERA_ALWAYS = "Force new era always";
static const char *STR_ME_CANCEL_DEFERRED_SLASH = "Cancel deferred slash";
static const char *STR_ME_PAYOUT_STAKERS = "Payout stakers";
static const char *STR_ME_REBOND = "Rebond";
static const char *STR_ME_REAP_STASH = "Reap stash";
static const char *STR_ME_KICK = "Kick";
static const char *STR_ME_SET_STAKING_CONFIGS = "Set staking configs";
static const char *STR_ME_CHILL_OTHER = "Chill other";
static const char *STR_ME_FORCE_APPLY_MIN_COMMISSION = "Force apply min commission";
static const char *STR_ME_SET_MIN_COMMISSION = "Set min commission";
static const char *STR_ME_PAYOUT_STAKERS_BY_PAGE = "Payout stakers by page";
static const char *STR_ME_UPDATE_PAYEE = "Update payee";
static const char *STR_ME_CHANGE_ENDPOINT = "Change endpoint";
static const char *STR_ME_CHANGE_THRESHOLD_ACCOUNTS = "Change threshold accounts";
static const char *STR_ME_DECLARE_SYNCED = "Declare synced";
static const char *STR_ME_SET_KEYS = "Set keys";
static const char *STR_ME_PURGE_KEYS = "Purge keys";
static const char *STR_ME_PROXY = "Proxy";
static const char *STR_ME_ADD_PROXY = "Add proxy";
static const char *STR_ME_REMOVE_PROXY = "Remove proxy";
static const char *STR_ME_REMOVE_PROXIES = "Remove proxies";
static const char *STR_ME_CREATE_PURE = "Create pure";
static const char *STR_ME_KILL_PURE = "Kill pure";
static const char *STR_ME_ANNOUNCE = "Announce";
static const char *STR_ME_REMOVE_ANNOUNCEMENT = "Remove announcement";
static const char *STR_ME_REJECT_ANNOUNCEMENT = "Reject announcement";
static const char *STR_ME_PROXY_ANNOUNCED = "Proxy announced";
static const char *STR_ME_REGISTER = "Register";
static const char *STR_ME_PRUNE_REGISTRATION = "Prune registration";
static const char *STR_ME_CHANGE_PROGRAM_INSTANCE = "Change program instance";
static const char *STR_ME_CONFIRM_REGISTER = "Confirm register";
static const char *STR_ME_SET_PROGRAM = "Set program";
static const char *STR_ME_REMOVE_PROGRAM = "Remove program";

// Items names
static const char *STR_IT_remark = "Remark";
static const char *STR_IT_pages = "Pages";
static const char *STR_IT_code = "Code";
static const char *STR_IT_items = "Items";
static const char *STR_IT_keys = "Keys";
static const char *STR_IT_prefix = "Prefix";
static const char *STR_IT_subkeys = "Subkeys";
static const char *STR_IT_code_hash = "Code hash";
static const char *STR_IT_calls = "Calls";
static const char *STR_IT_index = "Index";
static const char *STR_IT_call = "Call";
static const char *STR_IT_as_origin = "As origin";
static const char *STR_IT_weight = "Weight";
static const char *STR_IT_dest = "Dest";
static const char *STR_IT_amount = "Amount";
static const char *STR_IT_source = "Source";
static const char *STR_IT_keep_alive = "Keep alive";
static const char *STR_IT_who = "Who";
static const char *STR_IT_new_free = "New free";
static const char *STR_IT_direction = "Direction";
static const char *STR_IT_delta = "Delta";
static const char *STR_IT_payee = "Payee";
static const char *STR_IT_num_slashing_spans = "Num slashing spans";
static const char *STR_IT_prefs = "Prefs";
static const char *STR_IT_targets = "Targets";
static const char *STR_IT_new_ = "New";
static const char *STR_IT_additional = "Additional";
static const char *STR_IT_factor = "Factor";
static const char *STR_IT_invulnerables = "Invulnerables";
static const char *STR_IT_stash = "Stash";
static const char *STR_IT_era = "Era";
static const char *STR_IT_slash_indices = "Slash indices";
static const char *STR_IT_validator_stash = "Validator stash";
static const char *STR_IT_min_nominator_bond = "Min nominator bond";
static const char *STR_IT_min_validator_bond = "Min validator bond";
static const char *STR_IT_max_nominator_count = "Max nominator count";
static const char *STR_IT_max_validator_count = "Max validator count";
static const char *STR_IT_chill_threshold = "Chill threshold";
static const char *STR_IT_min_commission = "Min commission";
static const char *STR_IT_page = "Page";
static const char *STR_IT_controller = "Controller";
static const char *STR_IT_controllers = "Controllers";
static const char *STR_IT_maybe_controller = "Maybe controller";
static const char *STR_IT_maybe_total = "Maybe total";
static const char *STR_IT_maybe_unlocking = "Maybe unlocking";
static const char *STR_IT_endpoint = "Endpoint";
static const char *STR_IT_tss_account = "Tss account";
static const char *STR_IT_x25519_public_key = "X25519 public key";
static const char *STR_IT_server_info = "Server info";
static const char *STR_IT_synced = "Synced";
static const char *STR_IT_proof = "Proof";
static const char *STR_IT_real = "Real";
static const char *STR_IT_force_proxy_type = "Force proxy type";
static const char *STR_IT_delegate = "Delegate";
static const char *STR_IT_proxy_type = "Proxy type";
static const char *STR_IT_delay = "Delay";
static const char *STR_IT_spawner = "Spawner";
static const char *STR_IT_height = "Height";
static const char *STR_IT_ext_index = "Ext index";
static const char *STR_IT_call_hash = "Call hash";
static const char *STR_IT_program_modification_account = "Program modification account";
static const char *STR_IT_key_visibility = "Key visibility";
static const char *STR_IT_programs_data = "Programs data";
static const char *STR_IT_verifying_key = "Verifying key";
static const char *STR_IT_new_program_instance = "New program instance";
static const char *STR_IT_sig_req_account = "Sig req account";
static const char *STR_IT_signing_subgroup = "Signing subgroup";
static const char *STR_IT_new_program = "New program";
static const char *STR_IT_configuration_schema = "Configuration schema";
static const char *STR_IT_auxiliary_data_schema = "Auxiliary data schema";
static const char *STR_IT_oracle_data_pointer = "Oracle data pointer";
static const char *STR_IT_program_hash = "Program hash";

#ifdef __cplusplus
}
#endif
