  
  function initialize()
  {
    var dls = document.getElementsByTagName("DL");
    
    for (i = 0; i < dls.length; i++)
    {
      var dl = dls[i];
      switch (dl.id)
      {
        case "tera":
        case "nova":
        case "giga":
        case "peta":
        
          dl.onclick = goToLocation;
          dl.onmouseover = statusLocation;
          dl.onmouseout = clearStatus;
          break;
          
        default:
        
      }
    }
  }
  window.onload = initialize;
  
  function goToLocation()
  {
    for (j = 0; j < this.childNodes.length; j++)
    {
      var child = this.childNodes[j];
      if (child.nodeName == "DT")
      {
        for (k = 0; k < child.childNodes.length; k++)
        {
          var grandChild = child.childNodes[k];
          if (grandChild.nodeName == "A")
          {
            location.href = grandChild.href;
          }
        }
      }
    }
  }
  
  function statusLocation()
  {
    for (j = 0; j < this.childNodes.length; j++)
    {
      var child = this.childNodes[j];
      if (child.nodeName == "DT")
      {
        for (k = 0; k < child.childNodes.length; k++)
        {
          var grandChild = child.childNodes[k];
          if (grandChild.nodeName == "A")
          {
            window.status = grandChild.href;
          }
        }
      }
    }
  }
  
  function clearStatus()
  {
    window.status = '';
  } 

  