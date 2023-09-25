int f(char *s){
    return !(*s) ? 0 : 1 + f(s + 1);
}


int main()
{
    return(f("Oussama sallak"));
}