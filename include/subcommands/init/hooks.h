#pragma once

int pre_commit_hook();
int commit_msg_hook();
int applypatch_msg_hook();
int pre_applypatch_hook();
int pre_push_hook();
int pre_receive_hook();
int pre_rebase_hook();
int post_update_hook();
int pre_merge_commit_hook();
int push_to_checkout_hook();
int fsmonitor_watchman_hook();
int sendemail_validate_hook();
int update_hook();
int prepare_commit_msg_hook();
