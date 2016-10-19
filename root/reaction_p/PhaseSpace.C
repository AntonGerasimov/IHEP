void PhaseSpace() {
// example of use of TGenPhaseSpace
//Author: Valerio Filippini

   if (!gROOT->GetClass("TGenPhaseSpace")) gSystem->Load("libPhysics");

   TLorentzVector target(0.0, 0.0, 0.0, 0.938);
   TLorentzVector beam(0.0, 0.0, .65, .65);
   TLorentzVector W = beam + target;

   //(Momentum, Energy units are Gev/C, GeV)
   Double_t masses1[2] = { 0.135, 0.135} ;
   Double_t masses2[2] = { 0, 0};

   TGenPhaseSpace event1, event2, event3;
   event1.SetDecay(W, 2, masses1);

   TH1F *h1 = new TH1F("h1", "h1", 50,.0,1.0);
   TH1F *h2 = new TH1F("h2", "h2", 50,.0,1.0);
   TH1F *h3 = new TH1F("h3", "h3", 50,.0,1.0);
   TH1F *h4 = new TH1F("h4", "h4", 50,.0,1.0);
   for (Int_t n=0;n<100000;n++) {
      Double_t weight1 = event1.Generate();

      TLorentzVector *pPi1    = event1.GetDecay(0);
      TLorentzVector *pPi2    = event1.GetDecay(1);
 
      event2.SetDecay(*pPi1, 2, masses2);
      event3.SetDecay(*pPi2, 2, masses2);

      Double_t weight2 = event2.Generate();
      Double_t weight3 = event3.Generate();
    
      TLorentzVector *y[4];
      y[0] = event2.GetDecay(0);
      y[1] = event2.GetDecay(1);
      
      y[2] = event3.GetDecay(0);
      y[3] = event3.GetDecay(1);

      Float_t rand[4];
      Float_t px,py;
      TRandom3 random;
      for(int i=0; i<4; i++){      
          random.Rannor(rand[i],py);
      }
      

      int k=0;
      TLorentzVector sy[6];
      for (int i=0; i<4; i++){
          for (int j = i+1; j<4; j++){
              sy[k]=*y[i]+*y[j];
              h1->Fill(sy[k].M(), weight1*weight2*weight3);
              k++;
          }
      }

      TLorentzVector *old[4];
      old[0]=y[0]; old[1]=y[1]; old[2]=y[2]; old[3]=y[3];

      double sigma = 0.05;
      for (int i=0; i<4; i++){
            y[i]->SetE(old[i]->E()*(1+sigma*rand[i]));
            y[i]->SetPx(old[i]->Px()*(1+sigma*rand[i]));
            y[i]->SetPy(old[i]->Py()*(1+sigma*rand[i]));
            y[i]->SetPz(old[i]->Pz()*(1+sigma*rand[i]));           
      }

      k=0;
      for (int i=0; i<4; i++){
          for (int j = i+1; j<4; j++){
              sy[k]=*y[i]+*y[j];
              h2->Fill(sy[k].M(), weight1*weight2*weight3);
              k++;
          }
      }

      sigma = 0.1;
      for (int i=0; i<4; i++){
            y[i]->SetE(old[i]->E()*(1+sigma*rand[i]));
            y[i]->SetPx(old[i]->Px()*(1+sigma*rand[i]));
            y[i]->SetPy(old[i]->Py()*(1+sigma*rand[i]));
            y[i]->SetPz(old[i]->Pz()*(1+sigma*rand[i]));
      }
 
      k=0;
      for (int i=0; i<4; i++){
          for (int j = i+1; j<4; j++){
              sy[k]=*y[i]+*y[j];
              h3->Fill(sy[k].M(), weight1*weight2*weight3);
              k++;
          }
      }

      sigma = 0.5;
      for (int i=0; i<4; i++){
            y[i]->SetE(old[i]->E()*(1+sigma*rand[i]));
            y[i]->SetPx(old[i]->Px()*(1+sigma*rand[i]));
            y[i]->SetPy(old[i]->Py()*(1+sigma*rand[i]));
            y[i]->SetPz(old[i]->Pz()*(1+sigma*rand[i]));
      }
 
      k=0;
      for (int i=0; i<4; i++){
          for (int j = i+1; j<4; j++){
              sy[k]=*y[i]+*y[j];
              h4->Fill(sy[k].M(), weight1*weight2*weight3);
              k++;
          }
      }
 



   }
   TCanvas *c = new TCanvas("a");
   c->Divide(2,2);
   c->cd(1);
   h1->Draw();
   c->cd(2);
   h2->Draw();
   c->cd(3);
   h3->Draw();
   c->cd(4);
   h4->Draw();
}
