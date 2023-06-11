
int octadec::len()
{
    int i1 = a, i2 = 0;
    if (i1 == 0)
        while (i1)
        {
            i2++;
            i1 = i1 / 10;
        }
    return i2;
}