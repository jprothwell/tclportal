function checkval()
{
if(form1.s_name.value=="")
 {
  alert('请输入名称');
  form1.s_name.focus();
  return false;
 }
 if(form1.s_ktel.value=="")
 {
  alert('请输入客服电话');
  form1.s_ktel.focus();
  return false;
 }
}

function checkguest()
{
if(form1.g_subject.value=="")
 {
  alert('请输入标题');
  form1.g_subject.focus();
  return false;
 }
 if(form1.g_info.value=="")
 {
  alert('请输入内容');
  form1.g_info.focus();
  return false;
 }
}