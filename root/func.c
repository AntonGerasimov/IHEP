double func( double *x, double *p){
	return TMath::Exp(p[0]+x[0]/100);
}
void a(){
	TF1* f = new TF1("func", func, 0., 100., 1);
	f->SetParameter(0, 1);
	TCanvas *c = new TCanvas("a");
	c->Divide(3,2);
	c->cd(1);
	f->Draw();
	TH1F *hist1 = new TH1F("hist1", "hist2", 100, 0., 20.);
	for (int i=0; i<1000; i++){
		hist1->Fill(f->GetRandom());
	}
	c->cd(2);
	hist1->Draw();
	TH1F *hist2 = new TH1F("hist2", "hist2", 100, 0., 20.);
	for (int i=0; i<1000; i++){
		hist2->Fill(f->GetRandom());
	}
	c->cd(3);
	hist2->Draw();
	TH1F *hist3 = new TH1F("hist3", "hist3", 100, 0., 20.);
	hist3->Add(hist1, hist2, 2, 0.5);
	c->cd(4);
	hist3->Draw();
//	TH1F *hist4 = new TH1F("hist4", "hist4", 100, 0., 20.);
//	hist4->sumw2();
	
//	c->cd(5);
//	hist4->Draw();
//	c->Update();
}
