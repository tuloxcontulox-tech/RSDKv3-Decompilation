import sys

def check_balance(filename):
    with open(filename, 'r') as f:
        lines = f.readlines()

    braces = 0
    pps = []

    for i, line in enumerate(lines):
        # Braces
        braces += line.count('{')
        braces -= line.count('}')

        # Preprocessor
        stripped = line.strip()
        if stripped.startswith('#if'):
            pps.append((i + 1, stripped))
        elif stripped.startswith('#endif'):
            if not pps:
                print(f"Extra #endif at line {i+1} in {filename}")
            else:
                pps.pop()

    if braces != 0:
        print(f"Brace balance error in {filename}: {braces}")

    if pps:
        print(f"Unclosed preprocessor directives in {filename}:")
        for line_num, content in pps:
            print(f"  Line {line_num}: {content}")

if __name__ == "__main__":
    for arg in sys.argv[1:]:
        check_balance(arg)
