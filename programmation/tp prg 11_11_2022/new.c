int *t,n;
//malloc
t=(int*) malloc (n*sizeof(int));
  //malloc return : null || adresse
//realloc
t=(int*) realloc (t,(n+1)*sizeof(int))