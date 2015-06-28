<html>
<head><title>Hello World</title></head>
<body>
Hello World!<br/>
<%
  out.println("Your IP address is " + request.getRemoteAddr());
%>
<%! int day = 3; %>
<% if (day == 1 | day == 7) { %>
  <p> Today is weekend</p>
<% } else { %>
  <p> Today is not weekend</p>
<% } %>
</body>
</html>
