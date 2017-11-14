/*
 * Arduino DS3231 library API wrapper
 */

#include "arduino-shutters/src/Shutters.h"

#ifdef __cplusplus
extern "C"
{
#endif
																
typedef void (*OperationHandler)(Shutters* s, ShuttersOperation operation);
typedef char* (*ReadStateHandler)(Shutters* s, uint8_t length);
typedef void (*WriteStateHandler)(Shutters* s, const char* state, uint8_t length);
typedef void (*LevelReachedCallback)(Shutters* s, uint8_t level);

Shutters* mgos_shutters_create();
void mgos_shutters_close(Shutters* s);
void mgos_shutters_set_operation_handler(Shutters* s, OperationHandler handler);
void mgos_shutters_set_read_state_handler(Shutters* s, ReadStateHandler handler);
void mgos_shutters_set_write_state_handler(Shutters* s, WriteStateHandler handler);
void mgos_shutters_on_level_reached(Shutters* s, LevelReachedCallback callback);
void mgos_shutters_set_course_time(Shutters* s, uint32_t upCourseTime, uint32_t downCourseTime = 0);
void mgos_shutters_begin(Shutters* s);
void mgos_shutters_set_level(Shutters* s, uint8_t level);
void mgos_shutters_loop(Shutters* s);  

#ifdef __cplusplus
}
#endif  /* __cplusplus */
