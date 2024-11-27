int main(void)
{
    int x = 42;
    int 42 = x;  //- Error: expected unqualified-id
    
    int y = 0;
    x = y = 1;
    
    int z = 0;. //- Error: expected expression
    int w = x y; //- Error: expected ';' at end of declaration

}