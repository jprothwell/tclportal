function checkval()
{
if(form1.s_name.value=="")
 {
  alert('����������');
  form1.s_name.focus();
  return false;
 }
 if(form1.s_ktel.value=="")
 {
  alert('������ͷ��绰');
  form1.s_ktel.focus();
  return false;
 }
}

function checkguest()
{
if(form1.g_subject.value=="")
 {
  alert('���������');
  form1.g_subject.focus();
  return false;
 }
 if(form1.g_info.value=="")
 {
  alert('����������');
  form1.g_info.focus();
  return false;
 }
}