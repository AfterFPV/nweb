cd web
for f in *.json ; do ../client $f || echo ; done
