
default:	build

clean:
	rm -rf Makefile objs

build:
	$(MAKE) -f objs/Makefile
	$(MAKE) -f objs/Makefile manpage

install:
	$(MAKE) -f objs/Makefile install

upgrade:
	/home/qjiao/study/nginx/install/sbin/nginx -t

	kill -USR2 `cat /home/qjiao/study/nginx/install/logs/nginx.pid`
	sleep 1
	test -f /home/qjiao/study/nginx/install/logs/nginx.pid.oldbin

	kill -QUIT `cat /home/qjiao/study/nginx/install/logs/nginx.pid.oldbin`
