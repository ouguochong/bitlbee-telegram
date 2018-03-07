/*
 * Copyright (c) 2018 Guillaume Douézan-Grard
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <pthread.h>
#include <signal.h>

#include <bitlbee.h>

#define TD_API_KEY "replace me"
#define TD_API_HASH "replace me"

typedef void tgx_clt_t;
typedef struct im_connection im_connection_t;

typedef struct {
	int uid;

	GAsyncQueue *evts;

	im_connection_t *ic;

	tgx_clt_t *tc;

	sig_atomic_t sig;
	pthread_t thread;
} tgx_t;

// tdlib
tgx_clt_t *td_json_client_create();
void td_json_client_send(tgx_clt_t *, const char *request);
const char *td_json_client_receive(tgx_clt_t *, double timeout);
const char *td_json_client_execute(tgx_clt_t *, const char *request);
void td_json_client_destroy(tgx_clt_t *);
void td_set_log_verbosity_level(int level);
