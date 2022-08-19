## add problem description in the source file

import os

path = "./epi_judge_problems/"
code_path = "./epi_judge_cpp/"
files = os.listdir(path)

for file_name in files:
    if file_name.endswith(".txt"):
        prefix_name = file_name.split(".")[0]
        code_file = open(code_path + prefix_name + ".cc", "r")
        first_line = code_file.readline()
        lines = "// Description:\n"
        if first_line == lines:
            code_file.close()
            continue

        code_data = code_file.read()
        code_data = first_line + code_data
        code_file.close()

        code_file = open(code_path + prefix_name + ".cc", "w")

        desc_file = open(path + file_name)
        for line in desc_file:
            lines += "// " + line

        print(lines)

        code_file.write(lines + "\n\n" + code_data)
        desc_file.close()
        code_file.close()

        
