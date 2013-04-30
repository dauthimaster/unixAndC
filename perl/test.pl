$file = $ARGV[0];
$i = 1;

while (<>){
    if($_ =~ /\$.+=.+\;/){
        printf("%d %s", $i, $_);
    }
    ++$i;
}
