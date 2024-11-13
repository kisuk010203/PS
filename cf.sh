round="$1"
round_dir="Round$1"
cd "CodeForces"
mkdir $round_dir
cd $round_dir
for i in {A..F}; do
    pwd
    cp ../../template_cf.cpp "$round$i.cpp"
done

cd ../..
