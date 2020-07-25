function reverse(str) { 
    str2 = ""; 
    for (i = 0; i < str.length; i++) { 
        str2 += str[str.length - i - 1]; 
    } 
    return str2; 
}
rev = reverse("prova");
print("The reverse of prova is: " + rev);

do { 
    str = readline(); 
    rev = reverse(str); 
    print("The reverse of " + str + " is: " + rev); 
    print("Insert 1 to continue, 0 to exit"); 
    cont = readline(); 
} while (cont == 1)
    