//6. Calcule 10!
function factorializeif(num) {
    if (num < 0) 
          return -1;
    else if (num == 0) 
        return 1;
    else {
        return (num * factorializeif(num - 1));
    }
  }

  function factorializewhile(num) {
    var result = num;
    if (num === 0 || num === 1) 
      return 1; 
    while (num > 1) { 
      num--;
      result *= num;
    }
    return result;
  }

  function factorializefor(num) {
    if (num === 0 || num === 1)
      return 1;
    for (var i = num - 1; i >= 1; i--) {
      num *= i;
    }
    return num;
  }

  console.log(factorializeif(10));
  console.log(factorializewhile(10));
  console.log(factorializefor(10));
