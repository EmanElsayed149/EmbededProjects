//Learn In Depth
//by : Eman Elsayed 

.global reset

reset:
  ldr sp, =stacktop
  bl main
stop: b stop