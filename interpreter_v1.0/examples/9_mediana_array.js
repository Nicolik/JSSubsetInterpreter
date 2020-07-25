print("Inserisci n: ");
n = readline();
print("Inserisci elemento 0: ");
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

cc = aa;

bb = ordAsc(aa);

function getMediana(aa) {
    if (aa.length % 2 == 0) {
        c = (aa[aa.length/2 - 1] + aa[aa.length/2]) / 2;
    }
    else {
        c = aa[(aa.length-1)/2];
    }
    return c;
}

b = getMediana(bb);

print("La mediana di " + bb + " vale: " + b);