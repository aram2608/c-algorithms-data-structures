import sys
import subprocess

lldb_python_path = subprocess.check_output(['lldb', '-P'], text=True).strip()
sys.path.append(lldb_python_path)

import lldb # type: ignore

