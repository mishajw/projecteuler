import os
import argparse
import glob
import subprocess
import sys


def main(problem: int):
    matches = glob.glob(f"./src/p{problem:03}*")
    assert len(matches) == 1, f"Found more than one solution to problem: {matches}"
    
    solution_path = matches[0]
    _, solution_extension = os.path.splitext(solution_path)

    print(f"Running {solution_path}")

    if solution_extension.lower() == ".cpp":
        run_cpp(solution_path, problem)
    elif solution_extension.lower() == ".py":
        run_py(solution_path)
    else:
        raise AssertionError(f"Couldn't run solution with path {solution_path}")


def run_cpp(path: str, problem: int) -> None:
    if not os.path.isdir("bin"):
        os.mkdir("bin")
    output_path = f"./bin/p{problem:03}"
    build_command = subprocess.run(["clang++", "-std=c++17", "-O3", "-g", "-o", output_path, path])
    assert build_command.returncode == 0, "Build failed"
    subprocess.run([output_path])


def run_py(path: str) -> None:
    subprocess.run([sys.executable, path])


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--problem", "-p", type=int, required=True)
    args = parser.parse_args()
    main(args.problem)

