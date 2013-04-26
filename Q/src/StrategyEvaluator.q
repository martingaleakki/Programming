N:100
MaxSize:1
MaxPnl:10.0
THrs:65*60*60*100
Time: asc(09:30:00.000 + (neg N)?THrs)
Size:N ? (0 1 -1)
Pnl:(abs Size)*(N?MaxPnl)*(N?(-1 1))
Pnl[0]:0.0
Strategy1:([]Time:Time;Size:Size;Pnl:Pnl)


StrategyStats{
NumTrades:count x;
Times:x[`Time];
Sizes:x[`Size];
Pnl:x[`Pnl];

GrossProfit: sum Pnl * Pnl > 0;
GrossLoss: sum Pnl * Pnl < 0;
NetProfit: GrossProfit + GrossLoss;
AvgProfit: NetProfit % (NumTrades);
MaxProfit: max Pnl;
MaxLoss: min Pnl;
NumWinners: sum Pnl > 0;
NumLosers: NumTrades - NumWinners;
PercWinners: 100* NumWinners % NumTrades;
AvgWinners: GrossProfit % NumWinners;
AvgLosers: GrossLOss % NumLosers;




}