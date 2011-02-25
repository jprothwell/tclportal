 //go top
 function doTopItem(){   
   var length = seqSelect.options.length;
   var topV,topT;
   var tempV = new Array();
   var tempT = new Array();
   for(var i = 0; i < length; i++){
     if(seqSelect.options[i].selected){
       if(i == 0){
         return false;
       }
       topV = seqSelect.options[0].value;
       topT = seqSelect.options[0].text;
       seqSelect.options[0].value = seqSelect.options[i].value;
       seqSelect.options[0].text = seqSelect.options[i].text;
      
       for(var j = 1; j < length; j++){
         tempV[j] = seqSelect.options[j].value;
         tempT[j] = seqSelect.options[j].text;
         if(j == 1){
           seqSelect.options[1].value = topV;
           seqSelect.options[1].text = topT;
         }else if(j > i){
            break;     
         }else{
           seqSelect.options[j].value = tempV[j-1];
           seqSelect.options[j].text = tempT[j-1];
         }
       }
     }
   }
   seqSelect.options[0].selected = true;
 }
 
 //go bottom
 function doBottomItem(){  
   var length = seqSelect.options.length;
   var bottomV,bottomT;
   var tempV = new Array();
   var tempT = new Array();
   for(var i = 0; i < length; i++){
     if(seqSelect.options[i].selected){
       if(i == (length-1)){
         return false;
       }
       bottomV = seqSelect.options[length-1].value;
       bottomT = seqSelect.options[length-1].text;
       seqSelect.options[length-1].value = seqSelect.options[i].value;
       seqSelect.options[length-1].text = seqSelect.options[i].text;
      
       for(var j = length-2; j >= 0; j--){
         tempV[j] = seqSelect.options[j].value;
         tempT[j] = seqSelect.options[j].text;
         if(j == (length-2)){
           seqSelect.options[length-2].value = bottomV;
           seqSelect.options[length-2].text = bottomT;
         }else if(j < i){
            break;     
         }else{
           seqSelect.options[j].value = tempV[j+1];
           seqSelect.options[j].text = tempT[j+1];
         }
       }
     }
   }
   seqSelect.options[length-1].selected = true;
 }
 
 //go up 1
 function doUpItem(){   
   var length = seqSelect.options.length;
   var tempV,tempT;
   for(var i = 0; i < length; i++){
     if(seqSelect.options[i].selected){
       if(i == 0){
         return false;
       }
       tempV = seqSelect.options[i-1].value;
       tempT = seqSelect.options[i-1].text;
       seqSelect.options[i-1].value = seqSelect.options[i].value;  
       seqSelect.options[i-1].text = seqSelect.options[i].text;
       seqSelect.options[i].value = tempV;  
       seqSelect.options[i].text = tempT; 
       seqSelect.options[i-1].selected = true;
       break;     
     }
   }
 }
 
 //go down 1
 function doDownItem(){   
   var length = seqSelect.options.length;
   var tempV,tempT;
   for(var i = 0; i < length; i++){
       if(seqSelect.options[i].selected){
       if(i == (length-1)){
         return false;
       }
       tempV = seqSelect.options[i+1].value;
       tempT = seqSelect.options[i+1].text;
       seqSelect.options[i+1].value = seqSelect.options[i].value;  
       seqSelect.options[i+1].text = seqSelect.options[i].text;
       seqSelect.options[i].value = tempV;  
       seqSelect.options[i].text = tempT; 
       seqSelect.options[i+1].selected = true;
       break;     
     }
   }
 }

 function setCursor(objStyle,cursor){
   objStyle.cursor = cursor;
 }