function getGwid(){
		var spid = document.getElementById("spid").value;
		$.ajax({
		                type : "post",
		                url : "<%=request.getContextPath() %>/cgateway.do",
		               	data : "action=findGatewayBySp&spid="+spid,
		                datatype : "text",
		                success : function(data)
		                {  	
		                	$("#gwid").html(data);
		                },
		                error: function(){
		                	alert("something error,try again!");
		                }
		            });
	}