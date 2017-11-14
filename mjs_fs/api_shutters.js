let Shutters = {
  _create: ffi('void* mgos_shutters_create()'),
  _close: ffi('void mgos_shutters_close(void*)'),
  _soh: ffi('void mgos_shutters_set_operation_handler(void*, void (*)(int, userdata), userdata)'),
  _srsh: ffi('void mgos_shutters_set_read_state_handler(void*, char* (*)(userdata), userdata)'),
  _swsh: ffi('void mgos_shutters_set_write_state_handler(void*, void (*)(char*, userdata), userdata)'),
  _sct: ffi('void mgos_shutters_set_course_time(void*, int, int)'),
  _b: ffi('void mgos_shutters_begin(void*)'),
  _sl: ffi('void mgos_shutters_set_level(void*, int)'),
  _l: ffi('void mgos_shutters_loop(void*)'),
  
  _proto: {
    close: function() {
      return Shutters._close(this.shutters);
    },
    
    setOperationHandler: function (handler) {
      return Shutters._soh(this.shutters, handler);
    },
    
    setReadStateHandler: function (handler) {
      return Shutters._srsh(this.shutters, handler);
    },
    
    setWriteStateHandler: function (handler) {
      return Shutters._swsh(this.shutters, handler);
    },

	  setCourseTime: function(up, down) {
      return Shutters._sct(this.shutters, up, down);
    },
    
    begin: function() {
      return Shutters._b(this.shutters);
    },
    
    setLevel: function(level) {
      return Shutters._sl(this.shutters, level);
    },
    
    loop: function() {
      return Shutters._l(this.shutters);
    },
  },

  create: function() {
    let obj = Object.create(Shutters._proto);
    obj.shutters = Shutters._create();
    return obj;
  },

}
