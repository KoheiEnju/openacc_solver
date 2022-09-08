from pathlib import Path
from sys import stdin

from matplotlib import pyplot as plt


def main():
    data = [
        [float(f) for f in line.split(",")] for line in stdin.read().strip().split("\n")
    ]
    plt.plot(data)
    plt.savefig(Path(__file__).parent / "output.jpg")


if __name__ == "__main__":
    main()
