TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM TankFill
  VAR
    TankFillAuto_Cmd : BOOL := 0;
    TankValveOpen : BOOL := 0;
    Estop_Cmd : BOOL := 0;
    TankLevelHi_Alarm : BOOL := 0;
    TankLevelLo_Alarm : BOOL := 0;
    TankLevel_LIT : REAL := 10.0;
    TankEmpty_SP : REAL := 2.0;
    TankFull_SP : REAL := 8.0;
    TankLoAlarm_SP : REAL := 1.0;
    TankHiAlarm_SP : REAL := 9.0;
  END_VAR

  TankValveOpen := NOT(TankLevelHi_Alarm) AND TankFillAuto_Cmd;
  IF TankLevel_LIT <= TankEmpty_SP THEN
    TankFillAuto_Cmd := TRUE; (*set*)
  END_IF;
  IF Estop_Cmd OR TankLevelHi_Alarm OR TankLevel_LIT >= TankFull_SP THEN
    TankFillAuto_Cmd := FALSE; (*reset*)
  END_IF;
  TankLevelHi_Alarm := TankLevel_LIT >= TankHiAlarm_SP;
  TankLevelLo_Alarm := TankLevel_LIT <= TankLoAlarm_SP;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : TankFill;
  END_RESOURCE
END_CONFIGURATION
