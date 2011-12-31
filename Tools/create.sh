#!/bin/bash

if [ -z "$1" ]; then
	echo 'No name, no game'
	return
fi

loc='/home/alex/Desktop/'
name=$1
old_dir=$loc'default'
new_dir=$loc$name

# echo $old_dir
# echo $new_dir

cp -r $old_dir $new_dir
cd $new_dir

rename 's/default/'$name'/g' *
sed -i 's/default/'$name'/g' *

codeblocks $name.cbp >& /dev/null &
