#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM TANKFILL
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TANKFILLAUTO_CMD)
  __DECLARE_VAR(BOOL,TANKVALVEOPEN)
  __DECLARE_VAR(BOOL,ESTOP_CMD)
  __DECLARE_VAR(BOOL,TANKLEVELHI_ALARM)
  __DECLARE_VAR(BOOL,TANKLEVELLO_ALARM)
  __DECLARE_VAR(REAL,TANKLEVEL_LIT)
  __DECLARE_VAR(REAL,TANKEMPTY_SP)
  __DECLARE_VAR(REAL,TANKFULL_SP)
  __DECLARE_VAR(REAL,TANKLOALARM_SP)
  __DECLARE_VAR(REAL,TANKHIALARM_SP)

} TANKFILL;

void TANKFILL_init__(TANKFILL *data__, BOOL retain);
// Code part
void TANKFILL_body__(TANKFILL *data__);
#endif //__POUS_H
