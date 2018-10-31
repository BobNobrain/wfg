dir="$1"
class_name="$2"

if [[ "$dir" == "" ]]; then
    echo "Use: bash class.sh [dir] ClassName"
    exit 1
fi

if [[ "$class_name" == "" ]]; then
    class_name="$dir"
    dir=""
fi

namespace=""

if [[ "$dir" == "" ]]; then
    dir=""
else
    namespace="$dir"
    # dir="/${dir}/"
fi

header_file="./include/${dir}/${class_name}.h"
source_file="./src/${dir}/${class_name}.cpp"

echo "Created files: "

echo "$header_file"
echo "$source_file"

# Class.h
echo "#pragma once" > "$header_file"
echo >> "$header_file"

echo "namespace wfg {" >> "$header_file"
if [[ "$namespace" != "" ]]; then
    echo "namespace ${namespace} {" >> "$header_file"
fi
echo "    class ${class_name} {" >> "$header_file"
echo "    public:" >> "$header_file"
echo "        ${class_name}();" >> "$header_file"
echo "        virtual ~${class_name}();" >> "$header_file"
echo "    };" >> "$header_file"
if [[ "$namespace" != "" ]]; then
    echo "};" >> "$header_file"
fi
echo "};" >> "$header_file"

# Class.cpp
echo "#include \"${dir}/${class_name}.h\"" > "$source_file"
echo >> "$source_file"

echo "namespace wfg {" >> "$source_file"
if [[ "$namespace" != "" ]]; then
    echo "namespace ${namespace} {" >> "$source_file"
fi

echo "    ${class_name}::${class_name}() {" >> "$source_file"
echo "        // TODO" >> "$source_file"
echo "    }" >> "$source_file"

echo "    ${class_name}::~${class_name}() {" >> "$source_file"
echo "        // TODO" >> "$source_file"
echo "    }" >> "$source_file"

if [[ "$namespace" != "" ]]; then
    echo "};" >> "$source_file"
fi
echo "};" >> "$source_file"
