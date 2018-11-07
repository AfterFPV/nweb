cd web
for f in *.json;
do 
    ../client $f > test_$f.xml;
    tail -n +7 test_$f.xml | xmllint --noout -;
    echo $?; 
done
rm -f test_*.xml
echo "All 0s indicates passing"
