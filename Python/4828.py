import sys
import xml.etree.ElementTree as ET
input = sys.stdin.readline

# while True:
#     s = input().strip()
#     stack = []

def is_valid_xml(xml_string: str):
    stack = []
    idx = 0
    while idx < len(xml_string):
        if xml_string[idx] == "<":
            if idx + 1 < len(xml_string) and xml_string[idx + 1] == "/": # close tag
                idx += 2
                tag_name = ""
                for i in range(idx, len(xml_string)):
                    if xml_string[i] == ">":
                        break
                    elif xml_string[i] not in "abcdefghijklmnopqrstuvwxyz0123456789":
                        return False
                    tag_name += xml_string[i]
                else:
                    return False
                if not stack or stack[-1] != tag_name:
                    return False
                stack.pop()
                idx = i + 1
            else: # open tag
                idx += 1
                tag_name = ""
                for i in range(idx, len(xml_string)):
                    if xml_string[i] == ">":
                        break
                    elif xml_string[i] not in "abcdefghijklmnopqrstuvwxyz0123456789":
                        return False
                    tag_name += xml_string[i]
                else:
                    return False
                if tag_name[-1] != "/":
                    stack.append(tag_name)
                idx = i + 1
        elif xml_string[idx] == "&":
            if idx + 1 == len(xml_string):
                return False
            if xml_string[idx + 1] == "a":
                if idx + 4 >= len(xml_string) or xml_string[idx : idx + 5] != "&amp;":
                    return False
                idx += 5
            elif xml_string[idx + 1] == "l":
                if idx + 3 >= len(xml_string) or xml_string[idx : idx + 4] != "&lt;":
                    return False
                idx += 4
            elif xml_string[idx + 1] == "g":
                if idx + 3 >= len(xml_string) or xml_string[idx : idx + 4] != "&gt;":
                    return False
                idx += 4
            elif xml_string[idx + 1] == "x":
                for i in range(idx + 2, len(xml_string)):
                    if xml_string[i] == ";":
                        break
                    elif xml_string[i] not in "0123456789ABCDEF":
                        return False
                else:
                    return False
                if (i - idx) % 2 == 1:
                    return False
                idx = i + 1
            else:
                return False
        elif xml_string[idx] == ">":
            return False
        elif ord(xml_string[idx]) < 32 or ord(xml_string[idx]) > 127:
            return False
        else:
            idx += 1
    return not stack
        
ans = []
while True:
    s = input()
    if s == "":
        break
    ans.append("valid" if is_valid_xml(s.strip()) else "invalid")
print("\n".join(ans))