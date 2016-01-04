/**
 * Copyright 2014 University Corporation for Atmospheric Research. All rights
 * reserved. See the the file COPYRIGHT in the top-level source-directory for
 * licensing conditions.
 *
 *   @file: mldm_sender_map.h
 * @author: Steven R. Emmerson
 *
 * This file defines the API for a singleton mapping between feedtypes and
 * process-IDs of multicast LDM senders. The same mapping is accessible from
 * multiple processes and exists for the duration of the LDM session.
 */

#ifndef MLDM_SENDER_PIDS_H_
#define MLDM_SENDER_PIDS_H_

#include "ldm.h"

#include <stdbool.h>

#ifdef __cplusplus
    extern "C" {
#endif

/**
 * Initializes this module. Shall be called only once per LDM session.
 *
 * @retval 0            Success.
 * @retval LDM7_INVAL   This module is already initialized. `mylog_add()` called.
 * @retval LDM7_SYSTEM  System error. `mylog_add()` called.
 */
Ldm7Status
msm_init(void);

/**
 * Locks the map. Idempotent. Blocks until the lock is acquired or an error
 * occurs.
 *
 * @param[in] exclusive    Lock for exclusive access?
 * @retval    0            Success.
 * @retval    LDM7_SYSTEM  System failure. `mylog_add()` called.
 */
Ldm7Status
msm_lock(
        const bool exclusive);

/**
 * Adds a mapping between a feed-type and a multicast LDM sender process.
 *
 * @param[in] feedtype     Feed-type.
 * @param[in] pid          Multicast LDM sender process-ID.
 * @param[in] port         Port number of the VCMTP TCP server.
 * @retval    0            Success.
 * @retval    LDM7_DUP     Process identifier duplicates existing entry.
 *                         `mylog_add()` called.
 * @retval    LDM7_DUP     Feed-type overlaps with feed-type being sent by
 *                         another process. `mylog_add()` called.
 */
Ldm7Status
msm_put(
        const feedtypet      feedtype,
        const pid_t          pid,
        const unsigned short port);

/**
 * Returns process-information associated with a feed-type.
 *
 * @param[in]  feedtype     Feed-type.
 * @param[out] pid          Associated process-ID.
 * @param[out] port         Port number of the associated VCMTP TCP server.
 * @retval     0            Success. `*pid` and `*port` are set.
 * @retval     LDM7_NOENT   No process associated with feed-type.
 */
Ldm7Status
msm_get(
        const feedtypet                feedtype,
        pid_t* const restrict          pid,
        unsigned short* const restrict port);

/**
 * Unlocks the map.
 *
 * @retval    0            Success.
 * @retval    LDM7_SYSTEM  System failure. `mylog_add()` called.
 */
Ldm7Status
msm_unlock(void);

/**
 * Removes the entry corresponding to a process identifier.
 *
 * @param[in] pid          Process identifier.
 * @retval    0            Success. `msp_getPid()` for the associated feed-type
 *                         will return LDM7_NOENT.
 * @retval    LDM7_NOENT   No entry corresponding to given process identifier.
 *                         Database is unchanged.
 */
Ldm7Status
msm_remove(
        const pid_t pid);

/**
 * Clears all entries.
 */
void
msm_clear(void);

/**
 * Destroys this module. Should be called only once per LDM session.
 *
 * @retval 0            Success.
 * @retval LDM7_SYSTEM  System error. `mylog_add()` called.
 */
void
msm_destroy(void);

#ifdef __cplusplus
    }
#endif

#endif /* MLDM_SENDER_PIDS_H_ */
