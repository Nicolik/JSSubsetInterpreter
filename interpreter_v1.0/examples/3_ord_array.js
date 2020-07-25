print("Inserisci n: ");
n = readline();
aa = [readline()];
for (i = 0; i < n-1; i++) { 
    print("Inserisci elemento " + (i+1) + ": "); 
    aa.push(readline()); 
}

function ordAsc(aa) { 
    for (i = 0; i < aa.length-1; i++ ) { 
        min = i; 
        for (j = i+1; j < aa.length; j++ ) { 
            if(aa[j] < aa[min])  min = j; 
        } 
        temp = aa[min]; 
        aa[min] = aa[i]; 
        aa[i] = temp; 
    } 
    return aa; 
}

function ordDesc(aa) { 
    for (i = 0; i < aa.length-1; i++ ) { 
        max = i; 
        for (j = i+1; j < aa.length; j++ ) { 
            if(aa[j] > aa[max])  max = j; 
        } 
        temp = aa[max]; 
        aa[max] = aa[i]; 
        aa[i] = temp; 
    } 
    return aa; 
}

print("array non ordinato: " + aa);
cc = ordAsc(aa);
print("array ordinato (asc): " + cc);
dd = ordDesc(aa);
print("array ordinato (desc): " + dd);
