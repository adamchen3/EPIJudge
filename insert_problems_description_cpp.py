## add problem description in the source file

from math import fabs
import os

path = "./epi_judge_problems/"
code_path = "./epi_judge_cpp/"
files = os.listdir(path)

for file_name in files:
    if file_name.endswith(".txt"):
        prefix_name = file_name.split(".")[0]
        code_file = open(code_path + prefix_name + ".cc", "r")
        code_data = ""
        flag = False
        for line in code_file:
            if flag:
                code_data += line
                continue
            if line.startswith("#include"):
                code_data += line
                flag = True

        code_file.close()

        lines = "// Description:\n"
        code_file = open(code_path + prefix_name + ".cc", "w")

        desc_file = open(path + file_name)
        for line in desc_file:
            lines += "// " + line


        code_file.write(lines + "\n\n" + code_data)
        desc_file.close()
        code_file.close()

        
