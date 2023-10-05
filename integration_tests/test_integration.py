import subprocess
import unittest
import os


def run_eq_app(command: list[str]) -> str:
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)

    output = subprocess.check_output(command, stderr=subprocess.STDOUT, timeout=2)
    stdout_str, stderr_str = process.communicate()

    # Check if the command was successful (return code 0)
    if process.returncode == 0:
        print(stdout_str)
        return stdout_str.strip()
    else:
        return stderr_str.strip()


class TestResult(unittest.TestCase):
    def test_run_eq_app_ok(self):
        command = [os.environ['EQ_EXECUTABLE']]
        command.extend("Q 1 -2 -3 L 4 -4 Q 1 1 1 C 2 -12 22 -12 Q 1 a b".split())
        expected = "(1 -2 -3) => (3 -1)\n" \
                   "(4 -4) => (1)\n" \
                   "(1 1 1) => no roots\n" \
                   "(2 -12 22 -12) => (1 3 2)\n" \
                   "Bad coeffs pack (1 a b)! Skipping this equation."
        self.assertEqual(run_eq_app(command), expected)

    def test_run_eq_app_bad(self):
        command = [os.environ['EQ_EXECUTABLE'], "non_existing_file"]
        expected = "Unable to open input stream!"
        self.assertEqual(run_eq_app(command), expected)


if __name__ == '__main__':
    unittest.main()





