void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void TANKFILL_init__(TANKFILL *data__, BOOL retain) {
  __INIT_VAR(data__->TANKFILLAUTO_CMD,0,retain)
  __INIT_VAR(data__->TANKVALVEOPEN,0,retain)
  __INIT_VAR(data__->ESTOP_CMD,0,retain)
  __INIT_VAR(data__->TANKLEVELHI_ALARM,0,retain)
  __INIT_VAR(data__->TANKLEVELLO_ALARM,0,retain)
  __INIT_VAR(data__->TANKLEVEL_LIT,10.0,retain)
  __INIT_VAR(data__->TANKEMPTY_SP,2.0,retain)
  __INIT_VAR(data__->TANKFULL_SP,8.0,retain)
  __INIT_VAR(data__->TANKLOALARM_SP,1.0,retain)
  __INIT_VAR(data__->TANKHIALARM_SP,9.0,retain)
}

// Code part
void TANKFILL_body__(TANKFILL *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,TANKVALVEOPEN,,(!(__GET_VAR(data__->TANKLEVELHI_ALARM,)) && __GET_VAR(data__->TANKFILLAUTO_CMD,)));
  if ((__GET_VAR(data__->TANKLEVEL_LIT,) <= __GET_VAR(data__->TANKEMPTY_SP,))) {
    __SET_VAR(data__->,TANKFILLAUTO_CMD,,__BOOL_LITERAL(TRUE));
  };
  if (((__GET_VAR(data__->ESTOP_CMD,) || __GET_VAR(data__->TANKLEVELHI_ALARM,)) || (__GET_VAR(data__->TANKLEVEL_LIT,) >= __GET_VAR(data__->TANKFULL_SP,)))) {
    __SET_VAR(data__->,TANKFILLAUTO_CMD,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,TANKLEVELHI_ALARM,,(__GET_VAR(data__->TANKLEVEL_LIT,) >= __GET_VAR(data__->TANKHIALARM_SP,)));
  __SET_VAR(data__->,TANKLEVELLO_ALARM,,(__GET_VAR(data__->TANKLEVEL_LIT,) <= __GET_VAR(data__->TANKLOALARM_SP,)));

  goto __end;

__end:
  return;
} // TANKFILL_body__() 





