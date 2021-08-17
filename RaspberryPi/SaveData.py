import config

import pandas

class SaveData:
    def __init__(self):
        self.filepath = config.SAVE_FP
        self.save_df = None
        
        try:
            self.save_df = pandas.read_csv(config.SAVE_FP)
        except FileNotFoundError as e:
            column_names = ["HUNGER", "HAPPINESS", "SALAD", "CANDY", "BANK", "SICK", "RECOVERY", "MEDICINE", "CHILDREN", "CHILD_INC", "DISCIPLINE", "BASEWAGE", "BASEMARKET", "AGE", "DAYS"]
            start_stats = [[config.START_HUNGER, config.START_HAPPINESS, config.START_SALAD, config.START_CANDY, config.START_BANK, config.START_SICK, config.START_RECOVERY, config.START_MEDICINE, config.START_CHILDREN, config.START_CHILD_INC, config.START_DISCIPLINE, config.START_BASEWAGE, config.START_BASEMARKET, config.START_AGE, 0]]
            
            tmp_df = pandas.DataFrame(start_stats)
            tmp_df.to_csv(config.SAVE_FP, index=False, header=column_names, na_rep="None")
            
            self.save_df = pandas.read_csv(config.SAVE_FP)
            
    def get_curr_stats(self):
        tmp_df = self.save_df.tail(1)
        tmp_series = tmp_df.squeeze()
        tmp_list = [int(tmp_series['HUNGER']), int(tmp_series['HAPPINESS']), int(tmp_series['SALAD']), int(tmp_series['CANDY']), tmp_series['BANK'], int(tmp_series['SICK']), int(tmp_series['RECOVERY']), int(tmp_series['MEDICINE']), int(tmp_series['CHILDREN']), int(tmp_series['CHILD_INC']), int(tmp_series['DISCIPLINE']), tmp_series['BASEWAGE'], tmp_series['BASEMARKET'], int(tmp_series['AGE']), int(tmp_series['DAYS'])]
        
        return tmp_list
            
        
    
