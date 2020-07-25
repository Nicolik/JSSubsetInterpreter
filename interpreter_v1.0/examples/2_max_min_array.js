print("Inserisci n: ");
n = readline();
aa = [readline()];
for (i = 0; i < n-1; i++) { 
    print("Inserisci elemento " + (i+1) + ": "); 
    aa.push(readline()); 
}
print("Il vettore inserito aa = " + aa);

function max(aa) { 
    temp = aa[0];  
    for (i = 0; i < aa.length; i++) { 
        if (temp > aa[i]) { temp; } 
        else { temp = aa[i]; } 
    } 
    return temp; 
}
function min(aa) { 
    temp = aa[0];  
    for (i = 0; i < aa.length; i++) { 
        if (temp < aa[i]) { temp; } 
        else { temp = aa[i]; } 
    } 
    return temp; 
}
print("Il massimo di aa = " + max(aa) );
print("Il minimo di aa = " + min(aa) );
