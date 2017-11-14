#include "mgos_shutters.h"

Shutters* mgos_shutters_create() {
  return new Shutters();
}

void mgos_shutters_close(Shutters* s) {
  if (s == nullptr) return;
  
  delete s;
  s = nullptr;
}

void mgos_shutters_set_operation_handler(Shutters* s, OperationHandler handler) {
  if (s == nullptr) return;

  s->setOperationHandler(handler);
}

void mgos_shutters_set_read_state_handler(Shutters* s, ReadStateHandler handler) {
  if (s == nullptr) return;

  s->setReadStateHandler(handler);
}

void mgos_shutters_set_write_state_handler(Shutters* s, WriteStateHandler handler) {
  if (s == nullptr) return;
  
  s->setWriteStateHandler(handler);
}

void mgos_shutters_on_level_reached(Shutters* s, LevelReachedCallback callback) {
  if (s == nullptr) return;
  
  s->onLevelReached(callback);
}

void mgos_shutters_set_course_time(Shutters* s, uint32_t upCourseTime, uint32_t downCourseTime) {
  if (s == nullptr) return;

  s->setCourseTime(upCourseTime, downCourseTime);
}

void mgos_shutters_begin(Shutters* s) {
  if (s == nullptr) return;
  
  s->begin();
}

void mgos_shutters_set_level(Shutters* s, uint8_t level) {
  if (s == nullptr) return;
  
  s->setLevel(level);
}

void mgos_shutters_loop(Shutters* s) {
  if (s == nullptr) return;
  
  s->loop();
}
