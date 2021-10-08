/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _TD_DNODE_INT_H_
#define _TD_DNODE_INT_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "taoserror.h"
#include "taosmsg.h"
#include "tglobal.h"
#include "tlog.h"
#include "trpc.h"
#include "tstep.h"
#include "dnode.h"

struct SDnCfg;
struct SDnCheck;
struct SDnEps;
struct SDnMnEps;
struct SDnStatus;
struct SDnTelem;
struct SDnTrans;
struct SDnMain;

typedef struct SDnode {
  struct SSteps*    steps;
  struct SDnCfg*    cfg;
  struct SDnCheck*  check;
  struct SDnEps*    eps;
  struct SDnMnEps*  meps;
  struct SDnStatus* status;
  struct SDnTelem*  telem;
  struct SDnTrans*  trans;
  struct SDnMain*   main;
} SDnode;

SDnode* dnodeInst();

#define dFatal(...) { if (dDebugFlag & DEBUG_FATAL) { taosPrintLog("DND FATAL ", 255, __VA_ARGS__); }}
#define dError(...) { if (dDebugFlag & DEBUG_ERROR) { taosPrintLog("DND ERROR ", 255, __VA_ARGS__); }}
#define dWarn(...)  { if (dDebugFlag & DEBUG_WARN)  { taosPrintLog("DND WARN ", 255, __VA_ARGS__); }}
#define dInfo(...)  { if (dDebugFlag & DEBUG_INFO)  { taosPrintLog("DND ", 255, __VA_ARGS__); }}
#define dDebug(...) { if (dDebugFlag & DEBUG_DEBUG) { taosPrintLog("DND ", dDebugFlag, __VA_ARGS__); }}
#define dTrace(...) { if (dDebugFlag & DEBUG_TRACE) { taosPrintLog("DND ", dDebugFlag, __VA_ARGS__); }}

#ifdef __cplusplus
}
#endif

#endif /*_TD_DNODE_INT_H_*/