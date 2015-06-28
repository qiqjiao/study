<%@ page import="java.io.*,java.util.*" %>
<html>
    <head>
        <title>HTTP Header Request Example</title>
    </head>
    <body>
        <center>
            <h2>HTTP Header Request Example</h2>
            <table width="100%" border="1" align="center"> <tr bgcolor="#949494">
                    <th>Header Name</th><th>Header Value(s)</th> </tr>
                <%
                Enumeration headerNames = request.getHeaderNames();
                while (headerNames.hasMoreElements()) {
                    String paramName = (String)headerNames.nextElement();
                    out.print("<tr><td>" + paramName + "</td>\n");
                    String paramValue = request.getHeader(paramName);
                    out.println("<td> " + paramValue + "</td></tr>\n");
                }
                %>
            </table>
            <%
            Integer hitsCount =
            (Integer)application.getAttribute("hitCounter");
            if( hitsCount ==null || hitsCount == 0 ){
            /* First visit */
            out.println("Welcome to my website!");
            hitsCount = 1;
            }else{
            /* return visit */
            out.println("Welcome back to my website!");
            hitsCount += 1;
            }
            application.setAttribute("hitCounter", hitsCount);
            %>
            <p>Total number of visits: <%= hitsCount%></p>
        </center>
    </body>
</html>
