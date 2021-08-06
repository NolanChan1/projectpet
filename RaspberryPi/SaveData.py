import pandas
import config

class SaveData:
    def __init__(self):
        self.filepath = config.SAVE_FP
        self.save_df = None
        
        try:
            self.save_df = pandas.read_csv(config.SAVE_FP)
        except FileNotFoundError as e:
            column_names = ["HUNGER", "HAPPINESS", "SALAD", "CANDY", "BANK", "SICK", "RECOVERY", "MEDICINE", "CHILDREN", "PREGNANT", "DISCIPLINE", "BASEWAGE", "BASEMARKET", "AGE", "DAYS"]
            start_stats = [[config.START_HUNGER, config.START_HAPPINESS, config.START_SALAD, config.START_CANDY, config.START_BANK, config.START_SICK, config.START_RECOVERY, config.START_MEDICINE, config.START_CHILDREN, config.START_PREGNANT, config.START_DISCIPLINE, config.START_BASEWAGE, config.START_BASEMARKET, config.START_AGE, 0]]
            
            tmp_df = pandas.DataFrame(start_stats)
            tmp_df.to_csv(config.SAVE_FP, index=False, header=column_names, na_rep="None")
            
            self.save_df = pandas.read_csv(config.SAVE_FP)
            
    def get_curr_stats(self):
        tmp_df = self.save_df.tail(1)
        tmp_series = tmp_df.squeeze()
        tmp_list = [tmp_series['HUNGER'], tmp_series['HAPPINESS'], tmp_series['SALAD'], tmp_series['CANDY'], tmp_series['BANK'], tmp_series['SICK'], tmp_series['RECOVERY'], tmp_series['MEDICINE'], tmp_series['CHILDREN'], tmp_series['PREGNANT'], tmp_series['DISCIPLINE'], tmp_series['BASEWAGE'], tmp_series['BASEMARKET'], tmp_series['AGE'], tmp_series['DAYS']]
        
        return tmp_list
            
        
    
