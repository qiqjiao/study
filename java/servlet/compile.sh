javac -cp /usr/local/Cellar/tomcat/8.0.23/libexec/lib/servlet-api.jar:commons-fileupload-1.3.1.jar:commons-io-2.4.jar *.java
cp *.class /usr/local/Cellar/tomcat/8.0.23/libexec/webapps/ROOT/WEB-INF/classes/

/usr/local/Cellar/tomcat/8.0.23/libexec/bin/shutdown.sh && /usr/local/Cellar/tomcat/8.0.23/libexec/bin/startup.sh
