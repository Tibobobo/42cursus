import pandas as pd

def load(path: str) -> pd.DataFrame:
    return pd.read_csv(path)
