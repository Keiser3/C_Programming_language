// algo d'insertion en ordre croissant
for(i=0;i<n;i++)
{
    if(t[i]>=x)
    {
        pos=i;break;
    }
}
for(i=n;i>=pos;i--)
{
    t[i]=t[i-1];
}
t[pos]=x;
n++;
