
default:	build

clean:
	rm -rf Makefile objs

build:
	$(MAKE) -f objs/Makefile
	$(MAKE) -f objs/Makefile manpage

install:
	$(MAKE) -f objs/Makefile install

upgrade:
	/home/jqq/study/nginx/install/sbin/nginx -t

	kill -USR2 `cat /home/jqq/study/nginx/install/logs/nginx.pid`
	sleep 1
	test -f /home/jqq/study/nginx/install/logs/nginx.pid.oldbin

	kill -QUIT `cat /home/jqq/study/nginx/install/logs/nginx.pid.oldbin`
