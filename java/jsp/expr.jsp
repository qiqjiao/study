<%@ page import="java.io.*,java.util.*" %>
<%
    String title = "User Agent Example";
    %>
    <html>
        <head>
            <title><% out.print(title); %></title>
            </head>
        <body>
            <center>
                <h1><% out.print(title); %></h1>
                </center>
            <div align="center">
                <p>${header["user-agent"]}</p>
                </div>
            </body>
        </html>
